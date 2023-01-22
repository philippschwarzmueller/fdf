/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:16 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/22 14:10:12 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

mlx_t	*init_mlx(void);
void	close_hook(mlx_key_data_t keydata, void *param);
void	key_bindings(void *tmp);
void	toggle(mlx_key_data_t keydata, void *tmp);

int	main(int argc, char **argv)
{
	t_pref	pref;

	if (argc != 2)
		return (0);
	pref.off_x = 0;
	pref.off_y = 0;
	pref.map = parse_map(argv[argc - 1]);
	pref.mlx = init_mlx();
	pref.scale = 10;
	pref.rot_x = 0.45;
	pref.rot_y = 0.45;
	pref.projection = p_dimetric;
	pref.img = mlx_new_image(pref.mlx, WIDTH, HEIGHT);
	if (!pref.img || (mlx_image_to_window(pref.mlx, pref.img, 0, 0) < 0))
		return (0);
	draw_map(pref);
	mlx_loop_hook(pref.mlx, &key_bindings, &pref);
	mlx_key_hook(pref.mlx, &toggle, &pref);
	mlx_loop(pref.mlx);
	mlx_terminate(pref.mlx);
	free(pref.map->coords);
	free(pref.map);
	return (0);
}

void	toggle(mlx_key_data_t keydata, void *tmp)
{
	t_pref	*pref;

	pref = (t_pref *) tmp;
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		toggle_projection(MLX_KEY_P, pref);
}

void	key_bindings(void *tmp)
{
	t_pref	*pref;

	pref = (t_pref *) tmp;
	if (mlx_is_key_down(pref->mlx, MLX_KEY_J))
		move(MLX_KEY_J, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_K))
		move(MLX_KEY_K, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_H))
		move(MLX_KEY_H, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_L))
		move(MLX_KEY_L, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_J) && mlx_is_key_down(pref->mlx, MLX_KEY_LEFT_SHIFT))
		zoom(MLX_KEY_J, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_K) && mlx_is_key_down(pref->mlx, MLX_KEY_LEFT_SHIFT))
		zoom(MLX_KEY_K, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_LEFT))
		rotate(MLX_KEY_LEFT, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_RIGHT))
		rotate(MLX_KEY_RIGHT, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_UP))
		rotate(MLX_KEY_UP, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_DOWN))
		rotate(MLX_KEY_DOWN, pref);
	if (mlx_is_key_down(pref->mlx, MLX_KEY_ESCAPE))
	{
		mlx_delete_image(pref->mlx, pref->img);
		mlx_close_window(pref->mlx);
	}
}

mlx_t	*init_mlx(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "fdf", false);
	return (mlx);
}
