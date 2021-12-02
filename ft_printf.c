/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:04:29 by rpohlen           #+#    #+#             */
/*   Updated: 2021/12/02 17:41:32 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf_args(char c, va_list ap)
{
	if (c == 'c')
		return (ft_printf_c(va_arg(ap, int)));
	else if (c == 's')
		return (ft_printf_s(va_arg(ap, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_printf_id(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_printf_u(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_printf_x(va_arg(ap, unsigned int), 0));
	else if (c == 'X')
		return (ft_printf_x(va_arg(ap, unsigned int), 1));
	else if (c == 'p')
		return (ft_printf_p(va_arg(ap, void *)));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	write(1, "%", 1);
	write(1, &c, 1);
	return (2);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	size_t	count;

	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += ft_printf_args(str[i + 1], ap);
			i += 2;
		}
		else
		{
			write(1, str + i, 1);
			count++;
			i++;
		}
	}
	va_end(ap);
	return (count);
}
