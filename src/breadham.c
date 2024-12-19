/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:41:27 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/15 13:03:38 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel_img(t_data *data, int x, int y, int colour)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < data->w && y < data->h)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)dst = colour;
	}
}

void	value_swapper(t_data *data)
{
	double		temp1;
	double		temp2;
	uint32_t	tempc;

	temp1 = data->x0;
	temp2 = data->y0;
	tempc = data->startcol;
	data->x0 = data->x1;
	data->y0 = data->y1;
	data->startcol = data->endcol;
	data->x1 = temp1;
	data->y1 = temp2;
	data->endcol = tempc;
}

void	ft_putline_low(t_data *data)
{
	data->dx = data->x1 - data->x0;
	data->dy = data->y1 - data->y0;
	data->yi = 1;
	if (data->dy < 0)
	{
		data->yi = -1;
		data->dy = -data->dy;
	}
	data->dp = (2 * data->dy) - data->dx;
	data->y = data->y0;
	while (data->x0 < data->x1)
	{
		put_pixel_img(data, (int)(data->x0), (int)(data->y),
			select_colour(data));
		if (data->dp > 0)
		{
			data->y = data->y + data->yi;
			data->dp = data->dp + (2 * (data->dy - data->dx));
		}
		else
			data->dp = data->dp + 2 * data->dy;
		data->x0++;
		data->colpos++;
	}
}

void	ft_putline_high(t_data *data)
{
	data->dx = data->x1 - data->x0;
	data->dy = data->y1 - data->y0;
	data->xi = 1;
	if (data->dx < 0)
	{
		data->xi = -1;
		data->dx = -data->dx;
	}
	data->dp = (2 * data->dx) - data->dy;
	data->x = data->x0;
	while (data->y0 < data->y1)
	{
		put_pixel_img(data, (int)(data->x), (int)(data->y0),
			select_colour(data));
		if (data->dp > 0)
		{
			data->x = data->x + data->xi;
			data->dp = data->dp + (2 * (data->dx - data->dy));
		}
		else
			data->dp = data->dp + 2 * data->dx;
		data->y0++;
		data->colpos++;
	}
}

void	ft_putline(t_data *data)
{
	data->colpos = 0;
	data->increment = increment_calc(data);
	if (abs((int)data->y1 - (int)data->y0) < abs((int)data->x1 -(int)data->x0))
	{
		if (data->x0 > data->x1)
		{
			value_swapper(data);
			ft_putline_low(data);
		}
		else
			ft_putline_low(data);
	}
	else
	{
		if (data->y0 > data->y1)
		{
			value_swapper(data);
			ft_putline_high(data);
		}
		else
			ft_putline_high(data);
	}
}
