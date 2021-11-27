/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:21:23 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/27 20:57:04 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_x(void)
{
}

void	ft_printf_xx(void)
{
}

void	ft_printf_p(void *p)
{
	int	i;

	i = 11;
	while (i >= 0)
	{
		ft_puthex((long unsigned int)p >> i * 4 & 0xff, 0);
		i--;
	}
}
