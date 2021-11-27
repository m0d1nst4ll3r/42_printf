/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:27:41 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/27 20:55:43 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_puthex(char h, int hcase)
{
	if (h < 10)
		ft_putchar(h + '0');
	else if (hcase)
		ft_putchar(h - 10 + 'A');
	else
		ft_putchar(h - 10 + 'a');
}
