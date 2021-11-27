/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:07:38 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/27 20:54:46 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c(char c)
{
	write(1, &c, 1);
}

void	ft_printf_s(char *s)
{
	while (s && *s)
		write(1, s++, 1);
}

void	ft_printf_per(void)
{
	write(1, "%", 1);
}

void	ft_printf_id(int i)
{
	ft_putnbr(i);
}

void	ft_printf_u(unsigned int u)
{
	ft_putnbr(u);
}
