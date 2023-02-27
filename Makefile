# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 15:09:01 by pschwarz          #+#    #+#              #
#    Updated: 2023/01/31 10:18:32 by pschwarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = fdf
LIBFT = lib/libft/libft.a
MLX42 = lib/mlx42/libmlx42.a

SRC = src/fdf.c src/input.c src/draw.c src/move.c src/project.c src/utils.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) -o $(NAME) -lglfw

dependencies: $(LIBFT) $(MLX42)

$(LIBFT):
	git submodule init
	git submodule update
	cd lib/libft && $(MAKE)

$(MLX42):
	git submodule init
	git submodule update
	cd lib/mlx42 && $(MAKE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
