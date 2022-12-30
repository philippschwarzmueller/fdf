# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 15:09:01 by pschwarz          #+#    #+#              #
#    Updated: 2022/12/30 15:42:48 by pschwarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = fdf
LIBFT = lib/libft/libft.a
MLX42 = lib/mlx42/libmlx42.a

SRC = src/fdf.c

OBJ_DIR = obj
OBJ = $(SRC:/src/%.c=/$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): dependencies $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) -o $(NAME)

dependencies:
	git submodule init
	cd lib/libft && $(MAKE)
	cd lib/mlx42 && $(MAKE) -lglfw
