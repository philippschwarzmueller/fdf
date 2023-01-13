/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:16 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/13 17:47:41 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

mlx_t	*init_mlx(void);
void	close_hook(mlx_key_data_t keydata, void *param);

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
	mlx_key_hook(mlx, &close_hook, &pref);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(pref.map->coords);
	free(pref.map);
	return (0);
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
