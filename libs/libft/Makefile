# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 19:56:15 by fcharbon          #+#    #+#              #
#    Updated: 2024/01/15 20:20:24 by fcharbon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
SRC_DIR := ./libftrepo/
INCLUDE := libft.h
SRCS := ft_isalpha.c \
ft_strs_len.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_free_char.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putstr_fd.c \
ft_putnbr_fd.c \
ft_printchar.c \
ft_printf.c \
ft_printnbr_base.c \
ft_printnbr_base_u.c \
ft_printptr.c \
ft_printstr.c \
get_next_line.c \
get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)
# SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
# OBJS = $(addprefix $(SRC_DIR), $(OBJ_FILES))
LIBC := ar rc
LIBR := ranlib
RM := rm -f

all: $(NAME)

# obj: $(SRCS)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	$(LIBR) $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
