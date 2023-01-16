# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 15:09:01 by pschwarz          #+#    #+#              #
#    Updated: 2023/01/15 15:49:19 by pschwarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
NAME = fdf
LIBFT = lib/libft/libft.a
MLX42 = lib/mlx42/libmlx42.a

SRC = src/fdf.c src/input.c src/draw.c src/move.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

macbook: dependencies $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) -o $(NAME) -lglfw

$(NAME): dependencies $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) -o $(NAME) -I include -lglfw -L "$(HOME)/.brew/opt/glfw/lib/"

dependencies:
	git submodule update
	cd lib/libft && $(MAKE)
	cd lib/mlx42 && $(MAKE)
clean:
	rm -f $(OBJ)
	cd lib/libft && $(MAKE) fclean
	cd lib/mlx42 && $(MAKE) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
