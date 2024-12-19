/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_and_translation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:44:32 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/12 17:41:01 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_z(t_data *data)
{
	int		count;
	double	tempx;
	double	theta;
	double	angle;

	angle = 45 + data->angular_offset_z;
	theta = angle * data->pi_div_180;
	count = 0;
	while (count < data->num_of_pts)
	{
		tempx = data->arr_of_3dcrds[count].x;
		data->arr_of_3dcrds[count].x = tempx * cos(theta)
			+ data->arr_of_3dcrds[count].y * sin(theta);
		data->arr_of_3dcrds[count].y = tempx * -sin(theta)
			+ data->arr_of_3dcrds[count].y * cos(theta);
		count++;
	}
}

void	ft_rotate_x(t_data *data)
{
	int		count;
	double	tempy;
	double	theta;
	double	angle;

	angle = 35.264 + data->angular_offset_x;
	theta = angle * data->pi_div_180;
	count = 0;
	while (count < data->num_of_pts)
	{
		tempy = data->arr_of_3dcrds[count].y;
		data->arr_of_3dcrds[count].y = tempy * cos(theta)
			+ data->arr_of_3dcrds[count].z * sin(theta);
		data->arr_of_3dcrds[count].z = tempy * -sin(theta)
			+ data->arr_of_3dcrds[count].z * cos(theta);
		count++;
	}
}

//WARNING! Experimental Function!

void	deportation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_pts)
	{
		data->map_3dcrds[i].x = (data->map_3dcrds[i].x - data->movement_x)
			/ (data->og_sfx * data->magn);
		data->map_3dcrds[i].y = ((data->map_3dcrds[i].y - data->movement_y)
				/ (data->og_sfy * data->magn)) + data->min_y;
		i++;
	}
}

void	immigration(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_pts)
	{
		data->arr_of_2dcrds[i].x
			= ((data->arr_of_3dcrds[i].x + data->mapoffsetx)
				* (data->magn * data->og_sfx))
			+ data->movement_x + data->offset_x;
		data->arr_of_2dcrds[i].y = (data->arr_of_3dcrds[i].y - data->min_y)
			* (data->og_sfy * data->magn) + data->movement_y + data->offset_y;
		i++;
	}
}

void	update_image(t_data *data)
{
	data->rc = 0;
	data->cc = 0;
	data->sc = 0;
	paste_map_crds(data);
	if (data->enable_top == 0)
	{
		ft_rotate_45_z(data);
		ft_rotate_beta_x(data);
	}
	immigration(data);
	mlx_destroy_image(data->mlx, data->img);
	new_img(WINDOW_WIDTH, WINDOW_HEIGHT, data);
	line_looper(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
