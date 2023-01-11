/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:13:49 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/11 11:41:19 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	populate_map(char **mapstring, t_coordinates **map);
static char	**read_file_to_strings(char *path, int height);
static int	count_newlines(char *path);
static int	count_words(char const *s);

t_map	*parse_map(char *path)
{
	t_map	*res;
	char	**mapstring;

	res = malloc(sizeof(t_map));
	if (!res)
		return (NULL);
	res->height = count_newlines(path);
	mapstring = read_file_to_strings(path, res->height);
	res->width = count_words(mapstring[0]);
	res->coordinates = malloc((res->height * res->width
				* sizeof(t_coordinates *)) + sizeof(void *));
	if (!res)
		return (free(mapstring), NULL);
	populate_map(mapstring, res->coordinates);
	free(mapstring);
	return (res);
}

static void	populate_map(char **mapstring, t_coordinates **map)
{
	int		line;
	int		column;
	int		i;
	char	**line_strings;

	line = 0;
	column = 0;
	i = 0;
	while (mapstring[line] != NULL)
	{
		line_strings = ft_split(ft_strtrim(mapstring[line], "\n"), ' ');
		while (line_strings[column] != NULL)
		{
			map[i] = malloc(sizeof(t_coordinates) * 1);
			map[i]->x = column + 1;
			map[i]->y = line + 1;
			map[i]->z = ft_atoi(line_strings[column]);
			column++;
			i++;
		}
		column = 0;
		line++;
	}
	free(line_strings);
	map[i] = NULL;
}

static char	**read_file_to_strings(char *path, int height)
{
	char	**contents;
	int		fd;
	char	*curr_str;
	int		i;

	contents = malloc(sizeof(char *) * height + (sizeof(void *)));
	if (!contents)
		return (NULL);
	fd = open(path, O_RDONLY);
	i = 0;
	curr_str = " ";
	while (i < height && curr_str != NULL)
	{
		curr_str = get_next_line(fd);
		contents[i] = curr_str;
		i++;
	}
	contents[i] = NULL;
	close(fd);
	return (contents);
}

static int	count_newlines(char *path)
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
		if (str_helper)
			line_count++;
	}
	close(fd);
	return (line_count);
}

static int	count_words(char const *s)
{
	int		res;
	int		i;
	char	*trimmed_s;

	i = 0;
	res = 0;
	trimmed_s = ft_strtrim(s, "\n");
	while (trimmed_s[i] != '\0')
	{
		if (trimmed_s[i] == ' ')
			i++;
		else
		{
			res++;
			while (trimmed_s[i] && trimmed_s[i] != ' ')
				i++;
		}
	}
	return (res);
}
