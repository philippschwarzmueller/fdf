/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:16 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/04 11:07:34 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fdf.h"

char	**read_file(char *path);

int	main(int argc, char **argv)
{
	char	**test;
	int		i;

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

char	**read_file(char *path)
{
	char	**contents;
	int		fd;
	char	*curr_str;
	int		i;

	contents = malloc(sizeof(char *) * 20);
	fd = open(path, O_RDONLY);
	curr_str = " ";
	i = 0;
	while (curr_str != NULL)
	{
		curr_str = get_next_line(fd);
		contents[i] = curr_str;
		i++;
	}
	contents[i] = NULL;
	return (contents);
}
