/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:35:13 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/11 09:07:41 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_map(t_coordinates **map, int scale, mlx_t *mlx)
{
	mlx_image_t	*drawn_map;
	int			i;

	drawn_map = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!drawn_map || (mlx_image_to_window(mlx, drawn_map, 0, 0) < 0))
		return ;
	i = 0;
	while (map[i] != NULL)
	{
		mlx_put_pixel(drawn_map, map[i]->x * scale, map[i]->y * scale,
			0xFFFFFF);
		i++;
	}
}
