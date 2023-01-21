/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:29:19 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/21 18:16:38 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_coordinates	iso(t_coordinates coordinates, t_pref pref);
static t_coordinates	dimetric(t_coordinates coordinates, t_pref pref);

t_coordinates	project(t_coordinates coordinates, t_pref *pref)
{
	t_coordinates	res;

	res = coordinates;
	if (pref->projection == 'i')
		res = iso(coordinates, *pref);
	else if (pref->projection == 'd')
		res = dimetric(coordinates, *pref);
	return (res);
}

static t_coordinates	iso(t_coordinates coordinates, t_pref pref)
{
	t_coordinates	res;
	int				x;
	int				y;

	x = coordinates.x * pref.scale;
	y = coordinates.y * pref.scale;
	res.x = (x - y) * cos(pref.rot_x);
	res.y = (-coordinates.z * pref.scale + x + y) * sin(pref.rot_y);
	res.x += pref.off_x;
	res.y += pref.off_y;
	return (res);
}

static t_coordinates	dimetric(t_coordinates coordinates, t_pref pref)
{
	t_coordinates	res;
	int				x;
	int				y;
	int				z;

	x = coordinates.x * pref.scale;
	y = coordinates.y * pref.scale;
	z = coordinates.z * pref.scale;
	res.x = x + pref.rot_x * z * cos(pref.rot_y);
	res.y = y + pref.rot_x * z * sin(pref.rot_y);
	res.x += pref.off_x;
	res.y += pref.off_y;
	return (res);
}
