# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maruiz-p <maruiz-p@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/18 18:03:55 by maruiz-p          #+#    #+#              #
#    Updated: 2024/02/07 12:38:52 by maruiz-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/so_long.c src/player.c src/readmap.c src/resize.c src/parser.c src/mapchecker.c src/images.c src/ft_error.c src/flood_fill.c src/count_objects.c src/handler.c

OBJ = $(SRC:.c=.o)

MLX_PATH = MLX42
MLX = $(MLX_PATH)/libmlx42.a

LIBFT_PATH = libftproyectos
LIBFT = $(LIBFT_PATH)/libft.a

CC = gcc
CFLAGS = -g

LIB = ar rcs
LIB_SYS = -I include -lglfw -L "/Users/maruiz-p/.brew/opt/glfw/lib"

RM = rm -fr

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(LIB_SYS)

$(OBJ): src/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(MLX):
	@make -C $(MLX_PATH)

clean:
	$(RM) $(OBJ)
	make clean -C $(MLX_PATH)
	make clean -C $(LIBFT_PATH)

fclean:
	$(RM) $(NAME) $(OBJ) $(LIBFT) $(MLX)
	make fclean -C $(MLX_PATH)
	make fclean -C $(LIBFT_PATH)

re: fclean all

solong: all clean

.PHONY: all re clean fclean solong
