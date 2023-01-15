/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:16 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/15 18:49:11 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

mlx_t	*init_mlx(void);
void	close_hook(mlx_key_data_t keydata, void *param);
void	key_bindings(void *tmp);

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	t_pref	pref;

	if (argc != 2)
		return (0);
	pref.map = parse_map(argv[argc - 1]);
	mlx = init_mlx();
	pref.mlx = mlx;
	pref.scale = 10;
	draw_map(pref.map, mlx, pref);
	//mlx_key_hook(mlx, &close_hook, &pref);
	mlx_loop_hook(mlx, &key_bindings, &pref);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(pref.map->coords);
	free(pref.map);
	return (0);
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
}

mlx_t	*init_mlx(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "fdf", false);
	return (mlx);
}

void	close_hook(mlx_key_data_t keydata, void *param)
{
	t_pref	*pref;

	pref = (t_pref *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(pref->mlx, pref->img);
		mlx_close_window(pref->mlx);
	}
}
