/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:04:29 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/28 20:22:51 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_printf_args(char c, ...)
{
	if (c == 'c')
		return ;
	else if (c == 's')
		return ;
	else if (c == 'i' || c == 'd')
		return ;
	else if (c == 'x')
		return ;
	else if (c == 'X')
		return ;
	else if (c == 'p')
		return ;
	else
	{
		write(1, "%", 1);
		write(1, &c, 1);
	}
}

int	ft_printf(const char *str, int ac, ...)
{
	va_list	av;

	va_start(av, ac);
	va_end()
	(void)str;
	return (0);
}

int	main(void)
{
	void	*p;

	p = &p;
	ft_printf_c('H');
	ft_printf_s("ello\n");
	ft_printf_id(2147483647);
	ft_printf_c('\n');
	ft_printf_u(4000000000);
	ft_printf_c('\n');
	ft_printf_x(257, 0);
	ft_printf_c('\n');
	ft_printf_x(257, 1);
	ft_printf_c('\n');
	ft_printf_p(p);
	ft_printf_c('\n');
}
