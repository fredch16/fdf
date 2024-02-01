/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_business.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:56:54 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/01 23:33:51 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WINDOW_WIDTH 1700
#define WINDOW_HEIGHT 900

#include "fdf.h"
/*
void	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

void	esc_to_close(int keysym, t_mlx_shitter fmlx)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(fmlx->mlx);
		mlx_destroy_window(fmlx->mlx, fmlx->win);
	}
	return (0);
}

void	x_to_close(t_mlx_shitter *fmlx)
{
	mlx_loop_end(fmlx->mlx);
	mlx_destroy_window(fmlx->mlx, fmlx->win);
	return (0);
}
*/
void	initialise_mlx(t_data *data, t_mlx_shitter *fmlx)
{
	/*
	int	i;

	i = 0;
	*/
	fmlx->mlx = mlx_init();
	fmlx->win = mlx_new_window(fmlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "LUH PRETTY");
	/*	while (i < data->num_of_pts)
	{
		mlx_pixel_put(fmlx->mlx, fmlx->win, (int)(scaled_2ds[i].x),
				(int)(scaled_2ds[i].y), 0x00FFFFFF);
		i++;
	}*/
	line_looper(data, fmlx);
	mlx_loop(fmlx->mlx);
}
