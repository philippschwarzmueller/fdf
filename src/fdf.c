/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:16 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/11 08:55:08 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

mlx_t	*init_mlx(void);

int	main(int argc, char **argv)
{
	int				i;
	t_coordinates	**coordinate_map;
	mlx_t			*mlx;

	if (argc != 2)
		return (0);
	i = 0;
	coordinate_map = parse_map(argv[argc - 1]);
	while (coordinate_map[i] != NULL)
	{
		ft_printf("x: %d, y: %d, z: %d\n", coordinate_map[i]->x,
			coordinate_map[i]->y, coordinate_map[i]->z);
		i++;
	}
	mlx = init_mlx();
	draw_map(coordinate_map, 10, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(coordinate_map);
	return (0);
}

mlx_t	*init_mlx(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "fdf", false);
	return (mlx);
}
