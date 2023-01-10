/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:16 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/10 13:16:20 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	char		**test;
	int			i;

	if (argc != 2)
		return (0);
	i = 0;
	test = read_file(argv[argc - 1]);
	while (test[i] != NULL)
	{
		ft_printf("%s", test[i]);
		i++;
	}
	return (0);
}
