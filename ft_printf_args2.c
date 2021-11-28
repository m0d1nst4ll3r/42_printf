/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:21:23 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/28 19:13:49 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(int h, int hcase)
{
	return (ft_putnhex(h, hcase, 0));
}

int	ft_printf_p(void *p)
{
	return (ft_putaddr(p));
}
