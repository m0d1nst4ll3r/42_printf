/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:08:46 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/30 17:31:17 by rpohlen          ###   ########.fr       */
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

void	printf_lstclear(t_pflist *list);
void	printf_lstadd(t_pflist **list, char c);
int		printf_lstsize(t_pflist *list);

#endif
