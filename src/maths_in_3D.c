/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_in_3D.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:44:28 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/12 16:56:26 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#define PI 3.1415926535

void	ft_rotate_45_z(t_data *data)
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
			+ data->map_3dcrds[count].y * sin(theta);
		data->arr_of_3dcrds[count].y = tempx * -sin(theta)
			+ data->map_3dcrds[count].y * cos(theta);
		count++;
	}
}

void	ft_rotate_beta_x(t_data *data)
{
	int		count;
	double	tempy;
	double	theta;
	double	angle;

	angle = 35.264 + data->angular_offset_x;
	count = 0;
	theta = angle * data->pi_div_180;
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

//WARNING! Experimental Feature. 
//This may have bugs and function in unexpected ways. 
//Proceed with caution

void	ft_rotate_sphere(t_data *data, double radius)
{
	double	theta;
	double	phi;
	int		i;
	int		j;
	int		pos;

	i = 0;
	while (i < data->num_of_rows)
	{
		j = 0;
		while (j < data->num_of_cols)
		{
			pos = i * data->num_of_cols + j;
			theta = 2.0 * PI * j / data->num_of_cols;
			phi = PI * i / (data->num_of_rows - 1);
			data->arr_of_2dcrds[pos].x = (radius + data->arr_of_3dcrds[pos].z
					* data->magn) * sin(phi) * cos(theta) + 600;
			data->arr_of_2dcrds[pos].y = (radius + data->arr_of_3dcrds[pos].z
					* data->magn) * sin(phi) * sin(theta) + 300;
			j++;
		}
		i++;
	}
}
