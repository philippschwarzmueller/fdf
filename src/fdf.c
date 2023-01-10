/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:16 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/10 13:11:13 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	**read_file(char *path);

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

int	count_newlines(int fd)
{
	int		line_count;
	char	*str_helper;

	line_count = 0;
	str_helper = " ";
	while (str_helper != NULL)
	{
		str_helper = get_next_line(fd);
		line_count++;
	}
	return (line_count);
}

char	**read_file(char *path)
{
	char	**contents;
	int		fd;
	char	*curr_str;
	int		i;
	int		lines;

	fd = open(path, O_RDONLY);
	lines = count_newlines(fd);
	close(fd);
	contents = malloc(sizeof(char *) * lines + 1);
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
	close(fd);
	return (contents);
}
