/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:08:46 by rpohlen           #+#    #+#             */
/*   Updated: 2021/12/01 19:27:46 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>

//	This list will be used throughout our program to store printf's output
typedef struct s_pflist
{
	char			c;
	struct s_pflist	*next;
}					t_pflist;

/* -------------------------------------------------------------------- **
**	This structure is used to communicate flag values to sub-functions
**
**	- sharp		(#) puts a '0x' before value ('0X' for X)
**				x and X
**	- space		( ) adds a space before value if positive
**				i and d
**	- plus		(+) adds a plus before value if positive
**				i and d
**	- zero		(0n) pads value with n zeroes ('-' included)
**				u, i, d, x and X
**	- minus		(-n) pads value with n spaces to the right of the value
**				u, i, d, x, X, p, c and s
**	- width		(n) pads value with n spaces to the left of the value
**				u, i, d, x, X, p, c and s
**	- dot		(.n) effect differs depending on type of argument
**				s					limits s to n characters
**				u, i, d, x and X	pads value with n zeroes ('-' ignored)
**				can be used as (.*) to signify that the next argument
**				should be used as the flag's value.
**				can be used as (.m$), to signify that the m-th argument
**				should be used as the flag's value.
**				(.n) ignores all non-digit characters in its calculations
**
**	Padding with n characters means if value takes less than n characters,
**		add n - (length) characters to it.
**
**	When optional values are omitted, they are considered to be 0.
**	Sometimes, this means the flag is useless (ex: %.i), other times,
**		the flag can still have an effect (ex: %.s).
**	This is reflected by the flag having a negative value (typically, -1)
**		when it is absent and 0 when it is present with a 0 value.
**
**	Ambiguous cases:
**	- '0x' with any padding : the '0x' is counted in the length
**	- ' ' or '+' with any padding : the ' ' or '+' is counted
**	- ' ' and '+' both present : '+' takes precedence
**	- more than one of width, minus or 0 present :
**		- > 0 > width
**	- dot with '0x' : the '0x' is ignored
**	- dot with ' ' or '+' : both are ignored
**	- dot with width or minus : the zeroes are added before the spaces
**	- dot with 0 : 0 is completely ignored and taken out of the flag
**		if a value followed the 0, it is counted as a width value
**
**	Error cases:
**	- incompatible flag/conversion (ex: %#i), flag will be ignored
**	- incompatible flags, flags will have a priority
**		this behavior differs from the official printf
**		the official printf only ignores incompatible flags when they
**		have no values associated with them, otherwise it will count
**		their values as an incompatible string of regular characters
**		and print the entire instruction
** -------------------------------------------------------------------- */
typedef struct s_pfflags
{
	int	sharp;
	int	space;
	int	plus;
	int	zero;
	int	minus;
	int	width;
	int	dot;
}			t_pfflags;

/* -------------------------------------------------------------------- **
**	Useful features to add later:
**
**	- %m		prints the current errno with strerror(errno)
**	- %ld		for long ints
**	- %f		for doubles
**	- an fprintf which does the same thing as printf but with a channel
**		argument such as stderr or the fd of an open file.
** -------------------------------------------------------------------- */
void	printf_lstclear(t_pflist *list);
void	printf_lstadd_front(t_pflist **list, char c);
void	printf_lstadd_back(t_pflist **list, char c);
int		printf_lstsize(t_pflist *list);

#endif
