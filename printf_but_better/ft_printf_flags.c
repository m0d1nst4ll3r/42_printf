/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:00:18 by rpohlen           #+#    #+#             */
/*   Updated: 2021/12/02 19:05:30 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//	Resets all of the flags to their default -1 value
//	Used before encountering any % expression
void	reset_flags(t_pfflags *flags)
{
	flags->sharp = -1;
	flags->space = -1;
	flags->plus = -1;
	flags->zero = -1;
	flags->minus = -1;
	flags->width = -1;
	flags->dot = -1;
}

/* -------------------------------------------------------------------- **
**		update_flag
**
**	When encountering a flag, updates its corresponding value
**		in the flags structure.
**
**	Flags which can have an optional value after them require
**		an atoi function to be used, and will take that value.
**
**	Flags which don't are simply updated to 0 to signify their
**		existence.
**
**	- s			string starting at the expression
**	- flags		flags to update accordingly
**	- i			index of the flag we are updating, in the string
** -------------------------------------------------------------------- */
static void	update_flag(char *s, t_pfflags *flags, int *i)
{
	if (s[*i] == '#')
		flags->sharp = 0;
	else if (s[*i] == ' ')
		flags->space = 0;
	else if (s[*i] == '+')
		flags->plus = 0;
	else if (s[*i] == '0')
		flags->zero = ft_atoi(s, &(++(*i)));
	else if (s[*i] == '-')
		flags->minus = ft_atoi(s, &(++(*i)));
	else if (s[*i] == '.')
		flags->dot = ft_atoi(s, &(++(*i)));
	else if (s[*i] >= '1' && s[i] <= '9')
		flags->width = ft_atoi(s, &(++(*i)));
}

/* -------------------------------------------------------------------- **
**		flag_interpreter
**
**	Interprets expressions following a %
**
**	Evaluates flags one by one. Upon encountering a non-flag-compliant
**		character, that character must be a code for a conversion
**		(u i d x X c s p). If it is not, after we return -1,
**		the expression will be printed like a regular string.
**
**	Returns -1 for an invalid expression
**	or the length of the valid expression
**
**	- s			string starting at the expression to interpret
**	- flags		flags to update accordingly
** -------------------------------------------------------------------- */
int	flag_interpreter(char *s, t_pfflags *flags)
{
	unsigned int	i;

	i = 0;
	while (ft_strchr("# +0-.123456789", s[i]))
	{
		interpreter_sub(s, flags, &i);
		i++;
	}
	if (flags->space >= 0 && flags->plus >= 0)
		flags->space = -1;
	if (flags->width >= 0 && flags->minus >= 0)
		flags->width = -1;
	if (flags->zero >= 0 && flags->dot >= 0)
		flags->zero = 0;
	return (i - 1);
}
