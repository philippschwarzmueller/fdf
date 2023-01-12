/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:16 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/12 10:44:06 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

mlx_t	*init_mlx(void);
void	close_hook(mlx_key_data_t keydata, void *param);

int	main(int argc, char **argv)
{
	int			i;
	t_map		*map;
	mlx_t		*mlx;
	t_settings	settings;

	if (argc != 2)
		return (0);
	i = 0;
	map = parse_map(argv[argc - 1]);
	settings.map = map;
	while (map->coordinates[i] != NULL)
	{
		ft_printf("x: %d, y: %d, z: %d\n", map->coordinates[i]->x,
			map->coordinates[i]->y, map->coordinates[i]->z);
		i++;
	}
	mlx = init_mlx();
	settings.mlx = mlx;
	draw_map(map, 10, mlx, settings);
	mlx_key_hook(mlx, &close_hook, &settings);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(map->coordinates);
	free(map);
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
	t_settings	*settings;

	settings = (t_settings *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(settings->mlx, settings->img);
		mlx_close_window(settings->mlx);
	}
}
