/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:44:00 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/10 13:23:38 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./lib/libft/libft.h"
# include "./lib/mlx42/include/MLX42/MLX42.h"
# include <fcntl.h>

# define WIDTH 1280
# define HEIGHT 960

char	**read_map_from_file(char *path);

#endif
