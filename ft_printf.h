/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:03:07 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/28 19:13:32 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

//	Done :
//	c, s, i, d, u, %
//	TODO :
//	p
//	No idea how to do :
//	x, X (those say "number" but wtf does that mean? double?)

//	ft_printf_utils.c
int	ft_putnbr(long int n, int size);
int	ft_putchex(char h, int hcase);
int	ft_putnhex(long int h, int hcase, int size);
int	ft_putaddr(void *p);

//	ft_printf_args.c
int	ft_printf_c(char c);
int	ft_printf_s(char *s);
int	ft_printf_per(void);
int	ft_printf_id(int i);
int	ft_printf_u(unsigned int u);

//	ft_printf_args2.c
int	ft_printf_x(int h, int hcase);
int	ft_printf_p(void *p);

//	ft_printf.c
int	ft_printf(const char *s, ...);

#endif
