/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:13:49 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/10 13:15:33 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	count_newlines(int fd);

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
