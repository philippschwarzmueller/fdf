/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:35:13 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/11 15:56:50 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void				draw_line(t_coordinates start, t_coordinates end,
							mlx_image_t *image);
static t_coordinates	calc_iso(t_coordinates coordinates, int scale);

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
		if (map->coordinates[i]->x == map->width)
		{
			draw_line(calc_iso(*map->coordinates[i], scale),
				calc_iso(*map->coordinates[i + map->width], scale), drawn_map);
			i++;
		}
		if (map->coordinates[i]->y < map->height)
			draw_line(calc_iso(*map->coordinates[i], scale),
				calc_iso(*map->coordinates[i + map->width], scale), drawn_map);
		draw_line(calc_iso(*map->coordinates[i], scale),
			calc_iso(*map->coordinates[i + 1], scale), drawn_map);
		i++;
	}
	ft_printf("%d\n", scale);
}

static void	draw_line(t_coordinates start, t_coordinates end,
				mlx_image_t *image)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	ft_printf("On column: %d On line: %d\n", start.x, start.y);
	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = start.x;
	pixel_y = start.y;
	while (pixels)
	{
		mlx_put_pixel(image, pixel_x, pixel_y, 0xB7BDF8FF);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

static t_coordinates	calc_iso(t_coordinates coordinates, int scale)
{
	t_coordinates	res;

	res.x = coordinates.x * scale;
	res.y = coordinates.y * scale;
	return (res);
}
