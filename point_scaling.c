/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_scaling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:54:33 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/11 21:38:34 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//WEEEE WOOO FIX GLOBALS

#define SCREEN_WIDTH 1700
#define SCREEN_HEIGHT 900
#include "fdf.h"

void	scale_coords_x(t_data *data)
{
	double	min_x;
	double	max_x;
	double	scale_factor_x;
	int		i;

	i = 0;
	min_x = ft_fminx(data);
	data->min_x = min_x;
	max_x = ft_fmaxx(data);
	data->og_sfx = SCREEN_WIDTH / (max_x - min_x);
	data->movement_x = (SCREEN_WIDTH - (max_x - min_x)
			* (data->magn * data->og_sfx)) / 2.0 + data->offset_x;
	scale_factor_x = data->magn * data->og_sfx;
	scale_factor_x += 0;
	while (i < data->num_of_pts)
	{
		data->arr_of_2dcrds[i].x = (data->arr_of_3dcrds[i].x + data->mapoffsetx)
			* (data->magn * data->og_sfx) + data->movement_x;
		data->arr_of_2dcrds[i].colour = data->arr_of_3dcrds[i].colour;
		i++;
	}
}

void	scale_coords_y(t_data *data)
{
	double	min_y;
	double	max_y;
	double	scale_factor_y;
	int		i;

	i = 0;
	min_y = ft_fminy(data);
	data->min_y = min_y;
	max_y = ft_fmaxy(data);
	data->og_sfy = SCREEN_HEIGHT / (max_y - min_y);
	data->magn = 0.4;
	data->movement_y = (SCREEN_HEIGHT - (max_y - min_y)
			* (data->magn * data->og_sfy)) / 2.0 + data->offset_y;
	scale_factor_y = data->magn * data->og_sfy;
	scale_factor_y += 0;
	while (i < data->num_of_pts)
	{
		data->arr_of_2dcrds[i].y = (data->arr_of_3dcrds[i].y - data->min_y)
			* (data->magn * data->og_sfy) + data->movement_y;
		data->arr_of_2dcrds[i].colour = data->arr_of_3dcrds[i].colour;
		i++;
	}
}

void	paste_map_crds(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_pts)
	{
		data->arr_of_3dcrds[i].x = data->map_3dcrds[i].x;
		data->arr_of_3dcrds[i].y = data->map_3dcrds[i].y;
		data->arr_of_3dcrds[i].z = data->map_3dcrds[i].z;
		data->arr_of_3dcrds[i].colour = data->map_3dcrds[i].colour;
		i++;
	}
}

void	copy_map_crds(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_pts)
	{
		data->map_3dcrds[i].x = data->arr_of_3dcrds[i].x;
		data->map_3dcrds[i].y = data->arr_of_3dcrds[i].y;
		data->map_3dcrds[i].z = data->arr_of_3dcrds[i].z;
		data->map_3dcrds[i].colour = data->arr_of_3dcrds[i].colour;
		i++;
	}
}
