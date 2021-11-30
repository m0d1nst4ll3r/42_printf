/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:03:07 by rpohlen           #+#    #+#             */
/*   Updated: 2021/11/30 12:42:07 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

//	ft_printf_utils.c
void	ft_putnbr(long int n, int *count);
int		ft_putchex(char h, int hcase);
void	ft_putnhex(long int h, int hcase, int *count);
int		ft_putaddr(void *p);

//	ft_printf_args.c
int		ft_printf_c(char c);
int		ft_printf_s(char *s);
int		ft_printf_per(void);
int		ft_printf_id(int i);
int		ft_printf_u(unsigned int u);

//	ft_printf_args2.c
int		ft_printf_x(unsigned int h, int hcase);
int		ft_printf_p(void *p);

//	ft_printf.c
int		ft_printf(const char *s, ...);

#endif
