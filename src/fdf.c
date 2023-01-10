/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:16 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/04 15:20:18 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fdf.h"

char	**read_file(char *path);
void	draw_content(mlx_image_t image, char **content);

int	main(int argc, char **argv)
{
	char		**test;
	int			i;
	mlx_t		*window;
	mlx_image_t	*test_image;

	if (argc != 2)
		return (0);
	i = 0;
	test = read_file(argv[argc - 1]);
	while (test[i] != NULL)
	{
		ft_printf("%s", test[i]);
		i++;
	}
	window = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!window)
		ft_printf("failed to draw window");
	test_image = mlx_new_image(window, WIDTH, HEIGHT);
	draw_content(*test_image, test);
	mlx_image_to_window(window, test_image, 0, 0);
	mlx_loop(window);
	mlx_terminate(window);
	return (0);
}

void	draw_content(mlx_image_t image, char **content)
{
	int	i;
	int	j;
	int	line_offset;

	i = 0;
	j = 0;
	line_offset = 0;
	while (content[i] != NULL)
	{
		while (content[i][j] != '\0')
		{
			ft_memset(image.pixels + 5 * j + line_offset, 255, 5 * 5 * sizeof(int32_t));
			j++;
		}
		line_offset += WIDTH;
		i++;
	}
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
