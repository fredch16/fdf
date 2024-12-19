/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_business.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:56:54 by fcharbon          #+#    #+#             */
/*   Updated: 2024/12/16 17:54:44 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//USE ENUM TO DEFINE EVENTS AND KEYS

void	new_img(int w, int h, t_data *data)
{
	data->w = w;
	data->h = h;
	data->img = mlx_new_image(data->mlx, data->w, data->h);
	data->addr = mlx_get_data_addr(data->img, &(data->bpp),
			&(data->line_len), &(data->endian));
}

int	close_and_destroy(t_data *data)
{
	free_arr_of_2dcrds(data);
	free_arr_of_3dcrds(data);
	free_map_3dcrds(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	more_keyboard_inputs(int keysym, t_data *data)
{
	if (keysym == XK_r || keysym == XK_R)
	{
		data->offset_x = 0;
		data->offset_y = 0;
		data->angular_offset_x = 0;
		data->angular_offset_z = 0;
		data->magn = 0.4;
		data->enable_top = 0;
	}
	if (keysym == XK_t || keysym == XK_T)
		data->enable_top = 1;
	update_image(data);
	return (0);
}

int	keyboard_inputs(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_and_destroy(data);
	if (keysym == XK_Right)
		data->offset_x += 15;
	if (keysym == XK_Left)
		data->offset_x -= 15;
	if (keysym == XK_Up)
		data->offset_y -= 15;
	if (keysym == XK_Down)
		data->offset_y += 15;
	if (keysym == XK_q || keysym == XK_Q)
		data->angular_offset_z -= 2;
	if (keysym == XK_e || keysym == XK_E)
		data->angular_offset_z += 2;
	if (keysym == XK_d || keysym == XK_D)
		data->angular_offset_x += 2;
	if (keysym == XK_a || keysym == XK_A)
		data->angular_offset_x -= 2;
	if (keysym == XK_z || keysym == XK_Z)
		data->magn += 0.02;
	if ((keysym == XK_x || keysym == XK_X) && data->magn >= 0.02)
		data->magn -= 0.02;
	more_keyboard_inputs(keysym, data);
	return (0);
}

void	initialise_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "LUH PRETTY");
	new_img(WINDOW_WIDTH, WINDOW_HEIGHT, data);
	line_looper(data);
	mlx_hook(data->win, 17, 0, close_and_destroy, data);
	mlx_hook(data->win, 2, 1L << 0, keyboard_inputs, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
}
