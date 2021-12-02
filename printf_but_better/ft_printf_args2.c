/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_args2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:55:40 by rpohlen           #+#    #+#             */
/*   Updated: 2021/12/02 15:49:19 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* -------------------------------------------------------------------- **
**		printf_c
**
**	The following flags are taken into account :
**		- width		pad with ' ' to the left
**		- minus		pad with ' ' to the right
**
**	- c			the char to print
**	- list		the element to start writing from in the list
**	- flags		the flags (such as #05-8) in structure form
** -------------------------------------------------------------------- */
void	printf_c(char c, t_pflist **list, t_pfflags flags)
{
	printf_lstadd_back(list, c);
	if (flags.width > 0)
		printf_pad(list, flags.width - 1, 'l', ' ');
	if (flags.minus > 0)
		printf_pad(list, flags.width - 1, 'r', ' ');
}

/* -------------------------------------------------------------------- **
**		printf_s
**
**	The following flags are taken into account :
**		- dot		limit the amount of characters printed
**		- width		pad with ' ' to the left
**		- minus		pad with ' ' to the right
**
**	- s			the string to print
**	- list		the element to start writing from in the list
**	- flags		the flags (such as #05-8) in structure form
** -------------------------------------------------------------------- */
void	printf_s(char *s, t_pflist **list, t_pfflags flags)
{
	int	i;

	i = 0;
	while (s && (flags.dot < 0 || i < flags.dot) && s[i])
		printf_lstadd_back(list, s[i]);
	if (flags.width > 0)
		printf_pad(list, flags.width - printf_lstsize(*list), 'l', ' ');
	if (flags.minus > 0)
		printf_pad(list, flags.width - printf_lstsize(*list), 'r', ' ');
}

/* -------------------------------------------------------------------- **
 **		printf_p
 **
 **	The following flags are taken into account :
 **		- width		pad with ' ' to the left
 **		- minus		pad with ' ' to the right
 **
 **	- p			the pointer to print
 **	- list		the element to start writing from in the list
 **	- flags		the flags (such as #05-8) in structure form
 ** -------------------------------------------------------------------- */
void	printf_p(void *p, t_pflist **list, t_pfflags flags)
{
	int	i;

	printf_lstadd_back(list, '0');
	printf_lstadd_back(list, 'x');
	i = 15;
	while (i > 0 && ((long unsigned int)p >> (i * 4) & 0xf) == 0)
		i--;
	while (i >= 0)
	{
		printf_lstadd_back(list,
			ft_get_char((long unsigned int)p >> (i * 4) & 0xf, 0));
		i--;
	}
	if (flags.width > 0)
		printf_pad(list, flags.width - printf_lstsize(*list), 'l', ' ');
	if (flags.minus > 0)
		printf_pad(list, flags.width - printf_lstsize(*list), 'r', ' ');
}