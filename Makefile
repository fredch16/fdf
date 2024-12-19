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
SRCS := map_reading.c \
		coords_maxxing.c \
		point_scaling.c \
		maths_in_3D.c \
		print_that_jawn.c \
		linecon.c \
		breadham.c \
		mlx_business.c \
		freeallthemandem.c \
		rotation_and_translation.c \
		colours.c \
		main.c
INCLUDE := fdf.h
OBJ := $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lft -Llibs/libft -Llibs/mlx_linux -lm -lmlx_Linux -lXext -lX11 -lz -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME) mlxtest
re: fclean all

.PHONY: all clean fclean re
