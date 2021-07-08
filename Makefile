# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/03 21:50:59 by jimikim           #+#    #+#              #
#    Updated: 2021/07/03 23:00:53 by jimikim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ./header
SRCS = ./process/ft_process_p.c \
       ./process/ft_process_r.c \
       ./process/ft_process_rr.c \
       ./process/ft_process_s.c \
       ./sort/ft_a_to_b.c \
       ./sort/ft_a_to_b_sub.c \
       ./sort/ft_b_to_a.c \
       ./sort/ft_b_to_a_sub.c \
       ./sort/ft_range_five.c \
       ./sort/ft_range_three.c \
       ./sort/ft_range_three_a.c \
       ./sort/ft_range_three_b.c \
       ./sort/ft_under_three.c \
       ./utils/ft_utils_etc.c \
       ./utils/ft_utils_init.c \
       ./utils/ft_utils_math.c \
       ./utils/ft_utils_pivot.c \
       ./utils/ft_utils_set.c \
       ./utils/ft_utils_sort.c \
       ./utils/ft_utils_stack.c \
       ./utils/ft_utils_valid.c \
       ./libft/ft_atoi.c \
       ./libft/ft_isdigit.c \
       ./libft/ft_putnbr_fd.c \
       ./libft/ft_putstr_fd.c \
       ./libft/ft_split.c \
       ./libft/ft_strcmp.c \
       ./libft/ft_strlen.c \
       ./push_swap.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $^ -o $@

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re :
	make fclean
	make all

.PHONY :
	all
	clean
	fclean
	re
