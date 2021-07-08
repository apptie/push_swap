# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/03 23:41:27 by jimikim           #+#    #+#              #
#    Updated: 2021/07/04 11:54:19 by jimikim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ./header
SRCS = ./libft/ft_atoi.c \
       ./libft/ft_isdigit.c \
       ./libft/ft_putnbr_fd.c \
       ./libft/ft_putstr_fd.c \
       ./libft/ft_split.c \
       ./libft/ft_strcmp.c \
       ./libft/ft_strjoin.c \
       ./libft/ft_strlcat.c \
       ./libft/ft_strlcpy.c \
       ./libft/ft_strlen.c \
	   ./libft/ft_strtrim.c \
	   ./libft/ft_strchr.c \
	   ./libft/ft_strdup.c \
	   ./get_next_line/get_next_line.c \
	   ./get_next_line/get_next_line_utils.c \
       ./process/ft_process_p.c \
       ./process/ft_process_r.c \
       ./process/ft_process_rr.c \
       ./process/ft_process_s.c \
       ./utils/ft_utils_etc.c \
       ./utils/ft_utils_init.c \
       ./utils/ft_utils_set.c \
       ./utils/ft_utils_sort.c \
       ./utils/ft_utils_stack.c \
       ./utils/ft_utils_valid.c \
       ./checker.c
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
