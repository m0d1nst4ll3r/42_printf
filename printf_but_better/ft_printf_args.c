/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:29:03 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/30 17:31:15 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c(char c)
{
	write(1, &c, 1);
}

/*void	ft_printf_s(t_pfflags flags, char *s)
{
	size_t	i;

	while (s && i < flags. s[i])
}*/
