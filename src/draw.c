/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:35:13 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/12 10:37:59 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void				draw_line(t_coordinates start, t_coordinates end,
							mlx_image_t *image);
static t_coordinates	calc_iso(t_coordinates coordinates, int scale,
							int start_x, int start_y);
static int				calculate_center(int axis_size, char axis);

void	draw_map(t_map *map, int scale, mlx_t *mlx, t_pref pref)
{
	int				i;
	t_coordinates	iso_start;

	pref.offset_x = calculate_center(map->width, 'x');
	pref.offset_y = calculate_center(map->height, 'y');
	pref.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!pref.img || (mlx_image_to_window(mlx, pref.img, 0, 0) < 0))
		return ;
	i = 0;
	while (map->coordinates[i] != NULL && map->coordinates[i + 1] != NULL)
	{
		iso_start = calc_iso(*map->coordinates[i], scale, pref.offset_x, pref.offset_y);
		if (map->coordinates[i]->x == map->width)
		{
			draw_line(iso_start, calc_iso(*map->coordinates[i + map->width],
					scale, pref.offset_x, pref.offset_y), pref.img);
			i++;
			iso_start = calc_iso(*map->coordinates[i], scale, pref.offset_x, pref.offset_y);
		}
		if (map->coordinates[i]->y < map->height)
			draw_line(iso_start, calc_iso(*map->coordinates[i + map->width],
					scale, pref.offset_x, pref.offset_y), pref.img);
		draw_line(iso_start, calc_iso(*map->coordinates[i + 1], scale,
				pref.offset_x, pref.offset_y), pref.img);
		i++;
	}
}

static int	calculate_center(int axis_size, char axis)
{
	int	res;

	res = 0;
	if (axis == 'x')
		res = (WIDTH / 2) - (axis_size / 2);
	else if (axis == 'y')
		res = (HEIGHT / 2) - (axis_size / 2);
	return (res);
}

static void	draw_line(t_coordinates start, t_coordinates end,
				mlx_image_t *image)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = start.x;
	pixel_y = start.y;
	while (pixels)
	{
		if (pixel_x < image->width && pixel_y < image->height
			&& pixel_x > 0 && pixel_y > 0)
			mlx_put_pixel(image, pixel_x, pixel_y, 0xB7BDF8FF);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

static t_coordinates	calc_iso(t_coordinates coordinates, int scale,
							int start_x, int start_y)
{
	t_coordinates	res;
	int				x;
	int				y;

	x = coordinates.x * scale;
	y = coordinates.y * scale;
	res.x = (x - y) * cos(0.45);
	res.y = (-coordinates.z * scale + x + y) * sin(0.45);
	res.x += start_x;
	res.y += start_y;
	return (res);
}
