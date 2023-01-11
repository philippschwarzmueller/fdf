/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:16 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/11 11:13:48 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

mlx_t	*init_mlx(void);

int	main(int argc, char **argv)
{
	int		i;
	t_map	*map;
	mlx_t	*mlx;

	if (argc != 2)
		return (0);
	i = 0;
	map = parse_map(argv[argc - 1]);
	while (map->coordinates[i] != NULL)
	{
		ft_printf("x: %d, y: %d, z: %d\n", map->coordinates[i]->x,
			map->coordinates[i]->y, map->coordinates[i]->z);
		i++;
	}
	mlx = init_mlx();
	draw_map(map, 10, mlx);
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
