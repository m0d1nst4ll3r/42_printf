/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:27:41 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/28 19:13:34 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(long int n, int size)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		size++;
	}
	if (n > 9)
		return (ft_putnbr(n / 10, size + 1));
	ft_putchar(n % 10 + '0');
	return (size + 1);
}

int	ft_putchex(char h, int hcase)
{
	if (h < 10)
		ft_putchar(h + '0');
	else if (hcase)
		ft_putchar(h - 10 + 'A');
	else
		ft_putchar(h - 10 + 'a');
	return (1);
}

int	ft_putnhex(long int h, int hcase, int size)
{
	if (h < 0)
	{
		ft_putchar('-');
		h = -h;
		size++;
	}
	if (h > 15)
		return (ft_putnhex(h / 16, hcase, size + 1));
	ft_putchex(h % 16, hcase);
	return (size + 1);
}

int	ft_putaddr(void *p)
{
	int	i;

	write(1, "0x", 2);
	i = 11;
	while (i >= 0)
	{
		ft_putchex(((long unsigned int)p >> (i * 4)) & 0xf, 0);
		i--;
	}
	return (14);
}
