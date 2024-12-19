/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_maxxing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:21 by fcharbon          #+#    #+#             */
/*   Updated: 2024/01/29 19:39:56 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

double	ft_fminx(t_data *data)
{
	int		i;
	double	minx;

	i = 0;
	minx = INT_MAX;
	while (i < data->num_of_pts)
	{
		minx = fmin(minx, data->arr_of_3dcrds[i].x);
		i++;
	}
	return (minx);
}

double	ft_fminy(t_data *data)
{
	int		i;
	double	miny;

	i = 0;
	miny = INT_MAX;
	while (i < data->num_of_pts)
	{
		miny = fmin(miny, data->arr_of_3dcrds[i].y);
		i++;
	}
	return (miny);
}

double	ft_fmaxx(t_data *data)
{
	int		i;
	double	maxx;

	i = 0;
	maxx = INT_MIN;
	while (i < data->num_of_pts)
	{
		maxx = fmax(maxx, data->arr_of_3dcrds[i].x);
		i++;
	}
	return (maxx);
}

double	ft_fmaxy(t_data *data)
{
	int		i;
	double	maxy;

	i = 0;
	maxy = INT_MIN;
	while (i < data->num_of_pts)
	{
		maxy = fmax(maxy, data->arr_of_3dcrds[i].y);
		i++;
	}
	return (maxy);
}
