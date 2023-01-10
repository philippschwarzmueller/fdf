# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 15:09:01 by pschwarz          #+#    #+#              #
#    Updated: 2023/01/10 09:24:14 by pschwarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = fdf
LIBFT = lib/libft/libft.a
MLX42 = lib/mlx42/libmlx42.a

SRC = src/fdf.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): dependencies $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42) -o $(NAME)

dependencies:
	git submodule update
	cd lib/libft && $(MAKE)
	cd lib/mlx42 && $(MAKE) -lglfw

clean:
	rm -f $(OBJ)
	cd lib/libft && $(MAKE) fclean
	cd lib/mlx42 && $(MAKE) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
