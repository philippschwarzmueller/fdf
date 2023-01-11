/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:44:00 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/11 08:54:59 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./lib/libft/libft.h"
# include "./lib/mlx42/include/MLX42/MLX42.h"
# include <fcntl.h>

# define WIDTH 1280
# define HEIGHT 960

typedef struct s_coordinates
{
	int	x;
	int	y;
	int	z;
}	t_coordinates;

t_coordinates	**parse_map(char *path);
void			draw_map(t_coordinates **map, int scale, mlx_t *mlx);

#endif
