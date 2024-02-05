# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 19:56:15 by fcharbon          #+#    #+#              #
#    Updated: 2024/02/05 14:32:48 by fcharbon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := muh_fucka
CC := gcc
# PUT WERROR BACK
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
