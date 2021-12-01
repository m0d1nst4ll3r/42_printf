/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:29:03 by rpohlen           #+#    #+#             */
/*   Updated: 2021/12/01 19:12:24 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_c(char c, t_pflist **list, t_pfflags flags)
{
	printf_lstadd_back(list, c);
	if (flags.width > 0)
		return ;
	if (flags.minus > 0)
		return ;
}

/*void	printf_s(char *s, t_pflist **list, t_pfflags flags)
{
	size_t	i;
	size_t	len;

	(void)flags;
	while (s && s[len])
		len++;
	while (flags.dot > len)
	{
		printf_lstadd(list, ' ');
		flags.dot--;
	}
	while (len > 0)
	{
		len--;
	}
}*/
