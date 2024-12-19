# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 19:56:15 by fcharbon          #+#    #+#              #
#    Updated: 2024/12/19 14:34:45 by fcharbon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
SRCS := src/map_reading.c \
		src/coords_maxxing.c \
		src/point_scaling.c \
		src/maths_in_3D.c \
		src/print_that_jawn.c \
		src/linecon.c \
		src/breadham.c \
		src/mlx_business.c \
		src/freeallthemandem.c \
		src/rotation_and_translation.c \
		src/colours.c \
		src/main.c
INCLUDE := fdf.h
OBJ := $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lft -Lincludes/libft -Lincludes/mlx_linux -lm -lmlx_Linux -lXext -lX11 -lz -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME) mlxtest
re: fclean all

.PHONY: all clean fclean re
