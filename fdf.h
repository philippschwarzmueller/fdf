/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:44:00 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/12 10:38:23 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./lib/libft/libft.h"
# include "./lib/mlx42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 960

typedef struct s_coordinates
{
	int	x;
	int	y;
	int	z;
}	t_coordinates;

typedef struct s_map
{
	t_coordinates	**coordinates;
	int				width;
	int				height;
}	t_map;

typedef struct s_settings
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_settings;

t_map	*parse_map(char *path);
void	draw_map(t_map *map, int scale, mlx_t *mlx, t_settings settings);

#endif
