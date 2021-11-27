/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:03:07 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/27 20:57:16 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

//	Done :
//	c, s, i, d, u, %
//	TODO :
//	p
//	No idea how to do :
//	x, X (those say "number" but wtf does that mean? double?)

//	ft_printf_utils.c
void	ft_putnbr(long int n);
void	ft_puthex(char h, int hcase);

//	ft_printf_args.c
void	ft_printf_c(char c);
void	ft_printf_s(char *s);
void	ft_printf_per(void);
void	ft_printf_id(int i);
void	ft_printf_u(unsigned int u);

//	ft_printf_args2.c
void	ft_printf_x(void);
void	ft_printf_xx(void);
void	ft_printf_p(void *p);

int		ft_printf(const char *s, ...);

#endif
