/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:44:00 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/27 09:09:46 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./lib/libft/libft.h"
# include "./lib/mlx42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 960

typedef enum e_projections
{
	p_isometric,
	p_dimetric
}	t_projections;

typedef struct s_coordinates
{
	int	x;
	int	y;
	int	z;
}	t_coordinates;

typedef struct s_map
{
	t_coordinates	**coords;
	int				width;
	int				height;
}	t_map;

typedef struct s_pref
{
	t_map			*map;
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				scale;
	int				off_x;
	int				off_y;
	double			rot_x;
	double			rot_y;
	t_projections	projection;
}	t_pref;

t_map			*parse_map(char *path);
void			draw_map(t_pref pref);
void			move(int key, t_pref *pref);
void			zoom(int key, t_pref *pref);
void			rotate(int key, t_pref *pref);
t_coordinates	project(t_coordinates coordinates, t_pref *pref);
void			toggle_projection(int key, t_pref *pref);
void			ft_freestra(char **str_arr);
char			**ft_trimsplit(char *s);

#endif
