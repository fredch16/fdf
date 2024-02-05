/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:26:57 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/05 21:06:20 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libs/libft/libft.h"
# include "libs/mlx_linux/mlx.h"
# include <math.h>
# include <errno.h>
#include <X11/keysym.h>

typedef struct s_2d_vector
{
	double	x;
	double	y;
}	t_2d_vector;

typedef struct s_3d_vector
{
	double	x;
	double	y;
	double	z;
}	t_3d_vector;

typedef struct s_mlx_shitter
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
	int		colour;
	double	x0;
	double	y0;
	double	x1;
	double	y1;
}	t_mlx_shitter;

typedef struct s_data
{
	int			num_of_pts;
	t_2d_vector	*arr_of_2dcrds;
	t_3d_vector	*arr_of_3dcrds;
	int			num_of_rows;
	int			num_of_cols;
	double		offset_x;
	double		offset_y;

}	t_data;


double	ft_fminx(t_data *data);
double	ft_fminy(t_data *data);
double	ft_fmaxx(t_data *data);
double	ft_fmaxy(t_data *data);

char	**ft_get_map_lines(int map_fd);
char	***ft_mapline_to_str_value(char **map_lines);

void    ft_strval_to_3dvect (char ***map_str_vals, t_data *data);
void    ft_get_map(char *map_path, t_data *data);
void    ft_rotate_45_z(t_data *data);
void    ft_rotate_beta_x(t_data *data);
void	scale_coords_x(t_data *data);
void	scale_coords_y(t_data *data);
void    ft_print_coords2(t_data *data);
void	ft_print_coords(t_data *data);
void	connect_right(t_data *data, int index, t_mlx_shitter *fmlx);
void	connect_down(t_data *data, int index, t_mlx_shitter *fmlx);
void	ft_putline(t_mlx_shitter *fmlx);
void	line_looper(t_data *data, t_mlx_shitter *fmlx);
void	put_pixel_img(t_mlx_shitter *fmlx, int x, int y, int colour);
void	initialise_mlx(t_data *data, t_mlx_shitter *fmlx);
void	free_arr_of_3dcrds(t_data *data);
void	free_arr_of_2dcrds(t_data *data);
void	threed_to_pxpts(t_data *data);
#endif
