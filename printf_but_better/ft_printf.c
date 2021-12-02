/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:50:34 by rpohlen           #+#    #+#             */
/*   Updated: 2021/12/02 17:50:50 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_pflist	*output;
	int			len;

	if (! format)
		return (0);
	va_start(ap, format);
	output = NULL;
	printf_fill_output(format, ap, &output);
	va_end(ap);
	printf_print_output(output);
	len = printf_lstsize(output);
	printf_lstclear(output);
	return (len);
}
