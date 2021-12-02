/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_core.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:52:24 by rpohlen           #+#    #+#             */
/*   Updated: 2021/12/02 19:05:44 by rpohlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert(char code, t_pflist **output, t_pfflags)
{
	if (code == 'i' || format[i] == 'd')
		printf_i(va_arg(ap, int), output, flags);
	else if (format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
		printf_u(va_arg(ap, unsigned int), format[i], output, flags);
	else if (format[i] == 'c')
		printf_c((char)va_arg(ap, int), output, flags);
	else if (format[i] == 's')
		printf_s(va_arg(ap, char *), output, flags);
	else if (format[i] == 'p')
		printf_p(va_arg(ap, void *), output, flags);
	else

}

void	printf_fill_output(char *format, va_list ap, t_pflist **output)
{
	int			i;
	int			fi;
	t_pfflags	flags;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			
			fi = flag_interpreter(format + i, &flags);
			i += fi;
			if (format[i] == 'i' || format[i] == 'd')
				printf_i(va_arg(ap, int), output, flags);
			else if (format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
				printf_u(va_arg(ap, unsigned int), format[i], output, flags);
			else if (format[i] == 'c')
				printf_c((char)va_arg(ap, int), output, flags);
			else if (format[i] == 's')
				printf_s(va_arg(ap, char *), output, flags);
			else if (format[i] == 'p')
				printf_p(va_arg(ap, void *), output, flags);
			else
			{
				if (format[i] == '%')
					i++;
				i -= fi;
				printf_lstadd_back(output, '%');
			}
		}
		else
			printf_lstadd_back(output, format[i]);
		i++;
	}
}

void	printf_print_output(t_pflist *output)
{
	while (output)
	{
		write(1, &(output->c), 1);
		output = output->next;
	}
}
