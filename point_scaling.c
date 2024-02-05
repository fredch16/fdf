/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_scaling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:54:33 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/05 17:27:03 by fcharbon         ###   ########.fr       */
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
	max_x = ft_fmaxx(data);
	scale_factor_x = 0.8 * SCREEN_WIDTH / (max_x - min_x);
	while (i < data->num_of_pts)
	{
		data->arr_of_2dcrds[i].x = (data->arr_of_3dcrds[i].x) * scale_factor_x + (SCREEN_WIDTH
				- (max_x - min_x) * scale_factor_x) / 2.0 + data->offset_x;
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
	max_y = ft_fmaxy(data);
	scale_factor_y = 0.8 * SCREEN_HEIGHT / (max_y - min_y);
	while (i < data->num_of_pts)
	{
		data->arr_of_2dcrds[i].y = (data->arr_of_3dcrds[i].y - min_y) * scale_factor_y
			+ (SCREEN_HEIGHT - (max_y - min_y) * scale_factor_y) / 2.0 + data->offset_y;
		i++;
	}
}
