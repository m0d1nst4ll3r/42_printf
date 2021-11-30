/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:07:38 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/30 12:41:57 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_s(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		write(1, s + i, 1);
		i++;
	}
	return (i);
}

int	ft_printf_id(int i)
{
	int	count;

	count = 0;
	ft_putnbr(i, &count);
	return (count);
}

int	ft_printf_u(unsigned int u)
{
	int	count;

	count = 0;
	ft_putnbr(u, &count);
	return (count);
}

int	ft_printf_x(unsigned int h, int hcase)
{
	int	count;

	count = 0;
	ft_putnhex(h, hcase, &count);
	return (count);
}
