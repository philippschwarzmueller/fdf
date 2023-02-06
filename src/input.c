/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:13:49 by pschwarz          #+#    #+#             */
/*   Updated: 2023/02/06 08:15:20 by pschwarz         ###   ########.fr       */
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
	int		check_file;

	check_file = open(path, O_RDONLY);
	if (check_file < 0)
		return (close(check_file), NULL);
	close(check_file);
	res = malloc(sizeof(t_map));
	if (!res)
		return (NULL);
	res->height = count_newlines(path);
	mapstring = read_file_to_strings(path, res->height);
	res->width = count_words(mapstring[0]);
	res->coords = ft_calloc(res->height * res->width + 1,
			sizeof(t_coordinates *));
	if (!res)
		return (ft_freestra(mapstring), NULL);
	populate_map(mapstring, res->coords);
	ft_freestra(mapstring);
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
		line_strings = ft_trimsplit(mapstring[line]);
		while (line_strings[column] != NULL)
		{
			map[i] = malloc(sizeof(t_coordinates));
			map[i]->x = column + 1;
			map[i]->y = line + 1;
			map[i]->z = ft_atoi(line_strings[column]);
			column++;
			i++;
		}
		ft_freestra(line_strings);
		column = 0;
		line++;
	}
}

static char	**read_file_to_strings(char *path, int height)
{
	char	**contents;
	int		fd;
	int		i;

	contents = malloc(sizeof(char *) * height + (sizeof(void *)));
	if (!contents)
		return (NULL);
	fd = open(path, O_RDONLY);
	i = 0;
	while (i < height)
	{
		contents[i] = get_next_line(fd);
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
		free(str_helper);
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
	free(trimmed_s);
	return (res);
}
