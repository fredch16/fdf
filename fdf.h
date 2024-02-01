/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:26:57 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/01 23:21:31 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libs/libft/libft.h"
# include "libs/mlx_linux/mlx.h"
# include <math.h>

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

typedef struct s_3d_matrix
{
	t_3d_vector	i;
	t_3d_vector	j;
	t_3d_vector k;
}	t_3d_matrix;

typedef struct s_mlx_shitter
{
	void	*mlx;
	void	*win;
	int		colour;
	double	x0;
	double	y0;
	double	x1;
	double	y1;
}	t_mlx_shitter;

typedef struct s_map_element
{
	int			x;
	int			y;
	int			z;
	uint32_t	colour;
}	t_map_element;

typedef struct s_data
{
	int			num_of_pts;
	t_2d_vector	*arr_of_2dcrds;
	t_3d_vector	*arr_of_3dcrds;
	int			num_of_rows;
	int			num_of_cols;

}	t_data;


//int	arr_len_3d_vect(t_3d_vector *arr);


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
void	connect_right(t_data *data, int index,/* int rc, int cc,*/ t_mlx_shitter *fmlx);
void	connect_down(t_data *data, int index,/*int rc, int cc,*/ t_mlx_shitter *fmlx);
void	ft_putline(t_mlx_shitter *fmlx);
void	line_looper(t_data *data, t_mlx_shitter *fmlx);
void	handle_no_event(void *data);
void	esc_to_close(int keysym, t_mlx_shitter fmlx);
void	x_to_close(t_mlx_shitter *fmlx);
void	initialise_mlx(t_data *data, t_mlx_shitter *fmlx);

#endif
