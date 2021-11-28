/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:07:38 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/28 20:22:49 by rpohlen          ###   ########.fr       */
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
	return (ft_putnbr(i, 0));
}

int	ft_printf_u(unsigned int u)
{
	return (ft_putnbr(u, 0));
}
