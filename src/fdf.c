/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:16 by pschwarz          #+#    #+#             */
/*   Updated: 2023/02/06 08:44:25 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

mlx_t	*init_mlx(t_pref *pref);
void	close_hook(mlx_key_data_t keydata, void *param);
void	key_bindings(void *tmp);
void	toggles(mlx_key_data_t keydata, void *tmp);

int	main(int argc, char **argv)
{
	t_pref	pref;
	int		i;

	if (argc != 2)
		return (0);
	pref.mlx = init_mlx(&pref);
	pref.img = mlx_new_image(pref.mlx, WIDTH, HEIGHT);
	if (!pref.img || (mlx_image_to_window(pref.mlx, pref.img, 0, 0) < 0))
		return (0);
	pref.map = parse_map(argv[argc - 1]);
	if (!pref.map)
		return (mlx_terminate(pref.mlx), 1);
	draw_map(pref);
	mlx_loop_hook(pref.mlx, &key_bindings, &pref);
	mlx_key_hook(pref.mlx, &toggles, &pref);
	mlx_loop(pref.mlx);
	mlx_terminate(pref.mlx);
	i = 0;
	while (pref.map->coords[i] != NULL)
	{
		free(pref.map->coords[i]);
		i++;
	}
	return (free(pref.map->coords), free(pref.map), 0);
}

void	toggles(mlx_key_data_t keydata, void *tmp)
{
	t_pref	*pref;

	pref = (t_pref *) tmp;
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		toggle_projection(MLX_KEY_P, pref);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(pref->mlx, pref->img);
		mlx_close_window(pref->mlx);
	}
}

void	key_bindings(void *tmp)
{
	t_pref	*pref;
	int		shift_down;

	pref = (t_pref *) tmp;
	shift_down = mlx_is_key_down(pref->mlx, MLX_KEY_LEFT_SHIFT);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_J) && !shift_down)
		move(MLX_KEY_J, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_K) && !shift_down)
		move(MLX_KEY_K, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_H))
		move(MLX_KEY_H, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_L))
		move(MLX_KEY_L, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_J) && shift_down)
		zoom(MLX_KEY_J, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_K) && shift_down)
		zoom(MLX_KEY_K, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_LEFT))
		rotate(MLX_KEY_LEFT, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_RIGHT))
		rotate(MLX_KEY_RIGHT, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_UP))
		rotate(MLX_KEY_UP, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_DOWN))
		rotate(MLX_KEY_DOWN, pref);
}

mlx_t	*init_mlx(t_pref *pref)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "fdf", false);
	pref->off_x = 0;
	pref->off_y = 0;
	pref->scale = 10;
	pref->rot_x = 0.45;
	pref->rot_y = 0.45;
	pref->projection = p_isometric;
	return (mlx);
}
