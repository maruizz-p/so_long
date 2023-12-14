# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 18:03:55 by maruiz-p          #+#    #+#              #
#    Updated: 2023/11/24 12:29:11 by maruiz-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SO_LONG_PATH = ./so_long
MLX_FLAGS = -Imlx -Lmlx/ -lmlx -framework OpenGL -framework AppKit
MLX_PATH = ./MLX42
MLX = $(MLX_PATH)/libmlx42.a
LIBFT_PATH = ./libftproyectos
LIBFT = $(LIBFT_PATH)/libft.a

all: so_long

so_long: so_long.o main.o
	$(CC) $(CFLAGS) -o so_long so_long.o main.o -L. -lmlx -lXext -lX11

so_long.o: so_long.c so_long.h
	$(CC) $(CFLAGS) -c so_long.c

main.o: main.c so_long.h
	$(CC) $(CFLAGS) -c main.c

clean:
	$(RM) so_long.o main.o

fclean: clean
	$(RM) so_long

re: fclean all