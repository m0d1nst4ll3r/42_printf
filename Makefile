# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpohlen <rpohlen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 03:30:44 by rpohlen           #+#    #+#              #
#    Updated: 2021/12/05 03:54:45 by rpohlen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c \
			  ft_printf_utils.c \
			  ft_printf_utils_list.c \
			  ft_printf_utils_list2.c \
			  ft_printf_flags.c \
			  ft_printf_output.c \
			  ft_printf_args.c \
			  ft_printf_args2.c

SRCS_B		= ft_printf_bonus.c \
			  ft_printf_utils_bonus.c \
			  ft_printf_utils_list_bonus.c \
			  ft_printf_utils_list2_bonus.c \
			  ft_printf_flags_bonus.c \
			  ft_printf_output_bonus.c \
			  ft_printf_args_bonus.c \
			  ft_printf_args2_bonus.c

OBJS		= $(SRCS:.c=.o)

OBJS_B		= $(SRCS_B:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

libftprintf.a:	$(OBJS)
			ar rcs libftprintf.a $(OBJS)

all:		libftprintf.a

bonus:
			$(MAKE) -s SRCS="$(SRCS_B)"

clean:
			rm -rf $(OBJS) $(OBJS_B)

fclean:		clean
			rm -rf libftprintf.a

re:			fclean all
