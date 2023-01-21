/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:35:13 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/21 19:12:29 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void				draw_img(t_map *map, t_pref pref);
static void				draw_line(t_coordinates start, t_coordinates end,
							mlx_image_t *image);
static int				calculate_center(int axis_size, char axis);

void	draw_map(t_pref pref)
{
	pref.off_x = calculate_center(pref.off_x, 'x');
	pref.off_y = calculate_center(pref.off_y, 'y');
	ft_printf("drawing map with offset x: %d y: %d projected as: %c\n", pref.off_x, pref.off_y, pref.projection);
	ft_printf("also with: off_x %d off_y %d and scale %d", pref.off_x, pref.off_y, pref.scale);
	ft_bzero(pref.img->pixels, WIDTH * HEIGHT * 4);
	draw_img(pref.map, pref);
}

static int	calculate_center(int axis_size, char axis)
{
	int	res;

	res = 0;
	if (axis == 'x')
		res = (WIDTH / 2) + axis_size;
	else if (axis == 'y')
		res = (HEIGHT / 2) + axis_size;
	return (res);
}

static void	draw_img(t_map *map, t_pref pref)
{
	int				i;
	t_coordinates	start;

	i = 0;
	while (map->coords[i] != NULL && map->coords[i + 1] != NULL)
	{
		start = project(*map->coords[i], &pref);
		if (map->coords[i]->x == map->width)
		{
			draw_line(start, project(*map->coords[i + map->width], &pref),
				pref.img);
			i++;
			start = project(*map->coords[i], &pref);
		}
		if (map->coords[i]->y < map->height)
			draw_line(start, project(*map->coords[i + map->width], &pref),
				pref.img);
		draw_line(start, project(*map->coords[i + 1], &pref), pref.img);
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
		{
			/* if (start.z > 10)
				mlx_put_pixel(image, pixel_x, pixel_y, 0xDC8A78FF); */
			mlx_put_pixel(image, pixel_x, pixel_y, 0xB7BDF8FF);
		}
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}
