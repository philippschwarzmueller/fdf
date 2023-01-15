/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:35:13 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/15 19:50:44 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void				project(t_map *map, t_pref pref);
static void				draw_line(t_coordinates start, t_coordinates end,
							mlx_image_t *image);
static t_coordinates	iso(t_coordinates coordinates, int scale,
							int start_x, int start_y);
static int				calculate_center(int axis_size, char axis);

void	draw_map(t_map *map, mlx_t *mlx, t_pref pref)
{
	ft_printf("drawing map with offset x: %d y: %d\n", pref.off_x, pref.off_y);
	pref.off_x = calculate_center(map->width, 'x');
	pref.off_y = calculate_center(map->height, 'y');
	pref.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!pref.img || (mlx_image_to_window(mlx, pref.img, 0, 0) < 0))
		return ;
	project(pref.map, pref);
}

static int	calculate_center(int axis_size, char axis)
{
	long	res;

	res = 0;
	if (axis == 'x')
		res = (WIDTH / 2) + axis_size;
	else if (axis == 'y')
		res = (HEIGHT / 2) + axis_size;
	return (res);
}

static void	project(t_map *map, t_pref pref)
{
	int				i;
	t_coordinates	isostart;

	i = 0;
	while (map->coords[i] != NULL && map->coords[i + 1] != NULL)
	{
		isostart = iso(*map->coords[i], pref.scale, pref.off_x, pref.off_y);
		if (map->coords[i]->x == map->width)
		{
			draw_line(isostart, iso(*map->coords[i + map->width], pref.scale,
					pref.off_x, pref.off_y), pref.img);
			i++;
			isostart = iso(*map->coords[i], pref.scale, pref.off_x, pref.off_y);
		}
		if (map->coords[i]->y < map->height)
			draw_line(isostart, iso(*map->coords[i + map->width], pref.scale,
					pref.off_x, pref.off_y), pref.img);
		draw_line(isostart, iso(*map->coords[i + 1], pref.scale, pref.off_x,
				pref.off_y), pref.img);
		i++;
	}
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

static t_coordinates	iso(t_coordinates coordinates, int scale,
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
