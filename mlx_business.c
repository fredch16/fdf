/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_business.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:56:54 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/05 21:46:52 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WINDOW_WIDTH 1700
#define WINDOW_HEIGHT 900

#include "fdf.h"

//USE ENUM TO DEFINE EVENTS AND KEYS

int	close_and_destroy(t_mlx_shitter *fmlx, t_data *data)
{
	data += 0;
	mlx_destroy_window(fmlx->mlx, fmlx->win);
	mlx_destroy_image(fmlx->mlx, fmlx->img);
	mlx_destroy_display(fmlx->mlx);
	free(fmlx->mlx);
	exit(EXIT_SUCCESS);

	return (0);
}

int	keyboard_inputs(int keysym, t_mlx_shitter *fmlx, t_data *data)
{
	if (keysym == XK_Escape)
	{
		close_and_destroy(fmlx, data);
	}
	
/*	if (keysym == XK_Right)
	{
		data->offset_x += 5;
		threed_to_pxpts(data);
		line_looper(data, fmlx);
//		mlx_destroy_image(fmlx->mlx, fmlx->img);
		mlx_destroy_image(fmlx->mlx, fmlx->img);
		mlx_put_image_to_window(fmlx->mlx, fmlx->win, fmlx->img, 0, 0);
	}
	*/
	return (0);
}

void	new_img(int w, int h, t_mlx_shitter *fmlx)
{
	fmlx->w = w;
	fmlx->h = h;
	fmlx->img = mlx_new_image(fmlx->mlx, fmlx->w, fmlx->h);
	fmlx->addr = mlx_get_data_addr(fmlx->img, &(fmlx->bpp), &(fmlx->line_len), &(fmlx->endian));
}

void	put_pixel_img(t_mlx_shitter *fmlx, int x, int y, int colour)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < fmlx->w && y < fmlx->h) 
	{
		dst = fmlx->addr + (y * fmlx->line_len + x * (fmlx->bpp / 8));
	*(unsigned int *)dst = colour;
	}
}

void	initialise_mlx(t_data *data, t_mlx_shitter *fmlx)
{
	fmlx->mlx = mlx_init();
	fmlx->win = mlx_new_window(fmlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "LUH PRETTY");
	new_img(WINDOW_WIDTH, WINDOW_HEIGHT, fmlx);
	mlx_hook(fmlx->win, 17, 0, close_and_destroy, fmlx);
	mlx_hook(fmlx->win, 3, 1L<<1, keyboard_inputs, fmlx);
	line_looper(data, fmlx);
	mlx_put_image_to_window(fmlx->mlx, fmlx->win, fmlx->img, 0, 0);
	free_arr_of_2dcrds(data);
	mlx_loop(fmlx->mlx);
}
