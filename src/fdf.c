/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:16 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/10 17:54:45 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	int				i;
	t_coordinates	**coordinate_map;

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
	free(coordinate_map);
	return (0);
}
