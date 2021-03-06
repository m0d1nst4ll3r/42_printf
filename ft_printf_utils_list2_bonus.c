/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_list2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:22:24 by rpohlen           #+#    #+#             */
/*   Updated: 2021/12/05 15:24:34 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_pflist	**printf_lstlastp(t_pflist **list)
{
	t_pflist	*elem;

	if (! list)
		return (NULL);
	if (! *list)
		return (list);
	elem = *list;
	while (elem->next)
		elem = elem->next;
	return (&(elem->next));
}
