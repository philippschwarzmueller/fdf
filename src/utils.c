/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:06:51 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/27 09:11:51 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_freestra(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i] != NULL)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

char	**ft_trimsplit(char *s)
{
	char	*curr_line;
	char	**res;

	curr_line = ft_strtrim(s, "\n");
	res = ft_split(curr_line, ' ');
	free(curr_line);
	return (res);
}
