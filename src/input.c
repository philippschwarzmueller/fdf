/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:13:49 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/10 13:26:16 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	count_newlines(char *path);

char	**read_map_from_file(char *path)
{
	char	**contents;
	int		fd;
	char	*curr_str;
	int		i;
	int		lines;

	lines = count_newlines(path);
	contents = malloc(sizeof(char *) * lines + 1);
	if (!contents)
		return (NULL);
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

int	count_newlines(char *path)
{
	int		line_count;
	int		fd;
	char	*str_helper;

	fd = open(path, O_RDONLY);
	line_count = 0;
	str_helper = " ";
	while (str_helper != NULL)
	{
		str_helper = get_next_line(fd);
		line_count++;
	}
	close(fd);
	return (line_count);
}
