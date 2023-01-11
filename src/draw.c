/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:35:13 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/11 11:20:20 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	draw_line(t_coordinates *start, t_coordinates *end,
				mlx_image_t *image, int scale);

void	draw_map(t_map *map, int scale, mlx_t *mlx)
{
	mlx_image_t	*drawn_map;
	int			i;

	drawn_map = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!drawn_map || (mlx_image_to_window(mlx, drawn_map, 0, 0) < 0))
		return ;
	i = 0;
	while (map->coordinates[i] != NULL && map->coordinates[i + 1] != NULL)
	{
		if (map->coordinates[i]->y < map->coordinates[i + 1]->y)
			i++;
		draw_line(map->coordinates[i], map->coordinates[i + 1], drawn_map,
			scale);
		i++;
	}
	ft_printf("%d\n", scale);
}

static void	draw_line(t_coordinates *start, t_coordinates *end,
				mlx_image_t *image, int scale)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = end->x * scale - start->x * scale;
	delta_y = end->y * scale - start->y * scale;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = start->x * scale;
	pixel_y = end->y * scale;
	while (pixels)
	{
		mlx_put_pixel(image, pixel_x, pixel_y, 0xB7BDF8FF);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}
