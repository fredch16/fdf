/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:51:50 by fcharbon          #+#    #+#             */
/*   Updated: 2024/12/16 18:00:27 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	min_max_z(t_data *data)
{
	int	i;

	i = 0;
	data->min_z = INT_MAX;
	data->max_z = INT_MIN;
	while (i < data->num_of_pts)
	{
		data->min_z = fmin(data->min_z, data->arr_of_3dcrds[i].z);
		data->max_z = fmax(data->max_z, data->arr_of_3dcrds[i].z);
		i++;
	}
}

double	lerp(double a, double b, double t)
{
	return (a + t * (b - a));
}

int	colour_calculator(t_data *data, int zval)
{
	double		t;
	uint32_t	hexcolour;
	t_rgb		colour_min;
	t_rgb		colour_max;
	t_rgb		result;

	colour_min.red = 255;
	colour_min.green = 0;
	colour_min.blue = 255;
	colour_max.red = 255;
	colour_max.green = 255;
	colour_max.blue = 255;
	t = (zval - data->min_z) / (data->max_z - data->min_z);
	result.red = (uint8_t)lerp(colour_min.red, colour_max.red, t);
	result.green = (uint8_t)lerp(colour_min.green, colour_max.green, t);
	result.blue = (uint8_t)lerp(colour_min.blue, colour_max.blue, t);
	hexcolour = (result.red << 16) | (result.green << 8) | result.blue;
	return (hexcolour);
}

uint32_t	increment_calc(t_data *data)
{
	double		steps;
	uint32_t	increment;

	steps = fmax(fabs(data->x1 - data->x0), fabs(data->y1 - data->y0));
	if (data->startcol > data->endcol)
		increment = (data->startcol - data->endcol) / steps;
	else
		increment = (data->endcol - data->startcol) / steps;
	return (increment);
}

uint32_t	select_colour(t_data *data)
{
	uint32_t	next_colour;

	next_colour = data->startcol + (data->colpos * data->increment);
	if (next_colour > 0xFFFFFF)
		next_colour = data->startcol - (data->colpos * data->increment);
	return (next_colour);
}
