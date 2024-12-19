/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:26:57 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/12 17:36:54 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_WIDTH 1700
# define WINDOW_HEIGHT 900
# include "../includes/libft/libft.h"
# include "../includes/mlx_linux/mlx.h"
# include <math.h>
# include <errno.h>
# include <X11/keysym.h>

typedef struct s_2d_vector
{
	double			x;
	double			y;
	uint32_t		colour;
}	t_2d_vector;

typedef struct s_rgb
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
}	t_rgb;

typedef struct s_3d_vector
{
	double		x;
	double		y;
	double		z;
	uint32_t	colour;
}	t_3d_vector;

typedef struct s_data
{
	int			num_of_pts;
	t_2d_vector	*arr_of_2dcrds;
	t_3d_vector	*arr_of_3dcrds;
	t_3d_vector	*map_3dcrds;
	int			num_of_rows;
	int			num_of_cols;
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			h;
	int			w;
	int			bpp;
	int			endian;
	int			line_len;
	int			colour;
	int			enable_top;
	double		x0;
	double		y0;
	double		x1;
	double		y1;
	double		pi_div_180;
	double		offset_x;
	double		offset_y;
	double		angular_offset_x;
	double		angular_offset_y;
	double		angular_offset_z;
	char		*map_path;
	double		og_sfx;
	double		og_sfy;
	double		magn;
	double		movement_x;
	double		movement_y;
	double		min_y;
	double		min_x;
	double		min_z;
	double		max_z;
	double		mapoffsetx;
	double		mapoffsety;
	double		dx;
	double		dy;
	double		yi;
	double		xi;
	double		dp;
	double		y;
	double		x;
	int			rc;
	int			cc;
	int			sc;
	uint32_t	startcol;
	uint32_t	endcol;
	uint32_t	increment;
	int			colpos;
}	t_data;

uint32_t	increment_calc(t_data *data);
uint32_t	select_colour(t_data *data);

int			colour_calculator(t_data *data, int zval);

double		ft_fminx(t_data *data);
double		ft_fminy(t_data *data);
double		ft_fmaxx(t_data *data);
double		ft_fmaxy(t_data *data);

char		**ft_get_map_lines(int map_fd);
char		***ft_mapline_to_str_value(char **map_lines);

void		ft_strval_to_3dvect(char ***map_str_vals, t_data *data);
void		ft_get_map(char *map_path, t_data *data);
void		ft_rotate_45_z(t_data *data);
void		ft_rotate_beta_x(t_data *data);
void		ft_rotate_sphere(t_data *data, double radius);
void		ft_rotate_fisheye(t_data *data);
void		scale_coords_x(t_data *data);
void		scale_coords_y(t_data *data);
void		ft_print_coords3(t_data *data);
void		ft_print_coords2(t_data *data);
void		ft_print_coords(t_data *data);
void		connect_right(t_data *data, int index);
void		connect_down(t_data *data, int index);
void		ft_putline(t_data *data);
void		line_looper(t_data *data);
void		put_pixel_img(t_data *data, int x, int y, int colour);
void		initialise_mlx(t_data *data);
void		free_arr_of_3dcrds(t_data *data);
void		free_arr_of_2dcrds(t_data *data);
void		free_map_3dcrds(t_data *data);
void		threed_to_pxpts(t_data *data);
void		update_image(t_data *data);
void		new_img(int w, int h, t_data *data);
void		char_to_3d(t_data *data);
void		copy_map_crds(t_data *data);
void		update_2d_crds(t_data *data);
void		paste_map_crds(t_data *data);
void		min_max_z(t_data *data);

#endif
