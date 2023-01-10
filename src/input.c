/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:13:49 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/10 18:33:56 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int				count_newlines(char *path);
char			**read_map_from_file(char *path, int height);
t_coordinates	**map_coordinates(char **mapstring, int width, int height);
static int		count_words(char const *s);

t_coordinates	**parse_map(char *path)
{
	t_coordinates	**res;
	int				map_height;
	char			**mapstring;
	int				map_width;

	map_height = count_newlines(path);
	mapstring = read_map_from_file(path, map_height);
	map_width = count_words(mapstring[0]);
	ft_printf("map_height: %d \nmap_width: %d \n", map_height, map_width);
	res = map_coordinates(mapstring, map_width, map_height);
	free(mapstring);
	if (!res)
		return (NULL);
	return (res);
}

//TODO fucntion needs to be cleaned up
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
	ft_printf("%d\n", res);
	return (res);
}

t_coordinates	**map_coordinates(char **mapstring, int width, int height)
{
	t_coordinates	**res;
	int				line;
	int				column;
	int				i;
	char			**line_strings;

	res = malloc((height * width * sizeof(t_coordinates *)) + sizeof(void *));
	if (!res)
		return (NULL);
	line = 0;
	column = 0;
	i = 0;
	while (mapstring[line] != NULL)
	{
		line_strings = ft_split(ft_strtrim(mapstring[line], "\n"), ' ');
		while (line_strings[column] != NULL)
		{
			res[i] = malloc(sizeof(t_coordinates) * 1);
			res[i]->x = column + 1;
			res[i]->y = line + 1;
			res[i]->z = ft_atoi(line_strings[column]);
			column++;
			i++;
		}
		column = 0;
		line++;
	}
	free(line_strings);
	res[i] = NULL;
	return (res);
}

char	**read_map_from_file(char *path, int height)
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
		if (str_helper)
			line_count++;
	}
	close(fd);
	return (line_count);
}
