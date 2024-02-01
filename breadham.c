/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadham.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:41:27 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/01 22:15:54 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	value_swapper(t_mlx_shitter *fmlx)
{
	double	temp1;
	double	temp2;

	temp1 = fmlx->x0;
	temp2 = fmlx->y0;
	fmlx->x0 = fmlx->x1;
	fmlx->y0 = fmlx->y1;
	fmlx->x1 = temp1;
	fmlx->y1 = temp2;
}

void	ft_putline_low(t_mlx_shitter *fmlx)
{
	double	dx;
	double	dy;
	double	yi;
	double	dp;
	double	y;

	dx = fmlx->x1 - fmlx->x0;
	dy = fmlx->y1 - fmlx->y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	dp = (2 * dy) - dx;
	y = fmlx->y0;

	while (fmlx->x0 < fmlx->x1)
	{
		mlx_pixel_put(fmlx->mlx, fmlx->win, (int)(fmlx->x0), (int)(y), 0x00FFFFFF);
		if (dp > 0)
		{
			y = y + yi;
			dp = dp + (2 * (dy - dx));
		}
		else
			dp = dp + 2 * dy;
		fmlx->x0++;
	}
}

void	ft_putline_high(t_mlx_shitter *fmlx)
{
	double	dx;
	double	dy;
	double	xi;
	double	dp;
	double	x;

	dx = fmlx->x1 - fmlx->x0;
	dy = fmlx->y1 - fmlx->y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	dp = (2 * dx) - dy;
	x = fmlx->x0;

	while (fmlx->y0 < fmlx->y1)
	{
		//FIX PUT IMAGE LATER
		mlx_pixel_put(fmlx->mlx, fmlx->win, (int)(x), (int)(fmlx->y0), 0x00FFFFFF);
		if (dp > 0)
		{
			x = x + xi;
			dp = dp + (2 * (dx - dy));
		}
		else
			dp = dp + 2 * dx;
		fmlx->y0++;
	}
}

void	ft_putline(t_mlx_shitter *fmlx)
{
	if (abs((int)fmlx->y1 - (int)fmlx->y0) < abs((int)fmlx->x1 -(int)fmlx->x0))
	{
		if (fmlx->x0 > fmlx->x1)
		{
			value_swapper(fmlx);
			ft_putline_low(fmlx);
		}
		else
			ft_putline_low(fmlx);
	}
	else
	{
		if (fmlx->y0 > fmlx->y1)
		{
			value_swapper(fmlx);
			ft_putline_high(fmlx);
		}
		else
			ft_putline_high(fmlx);
	}
}

