/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:27:41 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/30 12:35:05 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long int n, int *count)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		(*count)++;
	}
	if (n > 9)
		ft_putnbr(n / 10, count);
	ft_putchar(n % 10 + '0');
	(*count)++;
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

void	ft_putnhex(long int h, int hcase, int *count)
{
	if (h < 0)
	{
		ft_putchar('-');
		h = -h;
		(*count)++;
	}
	if (h > 15)
		ft_putnhex(h / 16, hcase, count);
	ft_putchex(h % 16, hcase);
	(*count)++;
}

int	ft_putaddr(void *p)
{
	int	i;
	int	ret;

	write(1, "0x", 2);
	ret = 15;
	while (ret > 0 && ((long unsigned int)p >> (ret * 4) & 0xf) == 0)
		ret--;
	i = ret;
	while (i >= 0)
	{
		ft_putchex((long unsigned int)p >> (i * 4) & 0xf, 0);
		i--;
	}
	return (ret + 3);
}
