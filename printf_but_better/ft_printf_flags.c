/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:12:52 by rpohlen           #+#    #+#             */
/*   Updated: 2021/12/01 19:34:32 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------- **
**
** -------------------------------------------------------------------- */
void	printf_pad(t_pflist **list, int pad, char dir, char fill)
{
	int	i;
	int	len;

	len = printf_lstsize(*list);
	i = 0;
	while (i < pad - len)
	{
		if (dir == 'l')
			printf_lstadd_front(list, fill);
		else
			printf_lstadd_back(list, fill);
		i++;
	}
}
