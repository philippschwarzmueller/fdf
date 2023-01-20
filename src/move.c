/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:06:48 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/15 19:10:22 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	move(int key, t_pref *pref)
{
	if (key == MLX_KEY_J)
		pref->off_y -= 10;
	else if (key == MLX_KEY_K)
		pref->off_y += 10;
	else if (key == MLX_KEY_H)
		pref->off_x += 10;
	else if (key == MLX_KEY_L)
		pref->off_x -= 10;
	draw_map(*pref);
}

void	zoom(int key, t_pref *pref)
{
	if (key == MLX_KEY_DOWN)
		pref->scale += 1;
	if (key == MLX_KEY_UP)
		if (pref->scale > 0)
			pref->scale -= 1;
	draw_map(*pref);
}
