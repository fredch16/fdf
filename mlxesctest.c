/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxesctest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:39:33 by fcharbon          #+#    #+#             */
/*   Updated: 2024/01/25 18:38:30 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "fdf.h"

typedef struct	s_data {
	void	*win_ptr;
	void	*mlx_ptr;
}				t_data;

int handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int esc_to_close(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(data->mlx_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
		return (0);
}

int x_to_close(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);	
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1500, 800, "Mars2");


//	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
//	mlx_key_hook(data.win_ptr, &esc_to_close, &data); //change this to handle event later and then
													  //have a bunch of luh functions for each key
	mlx_hook(data.win_ptr, 17, 1L << 17, (int (*)())x_to_close, &data);
	mlx_hook(data.win_ptr, 2, 1L << 0, (int (*)())esc_to_close, &data);
	mlx_loop(data.mlx_ptr);

//	mlx_destroy_display(data.mlx_ptr);
//	free(data.mlx_ptr);

	ft_get_map("./map.fdf");
	t_3d_vector *rotated_3ds = ft_rotate_beta_x(ft_rotate_45_z(ft_get_map("./map.fdf")));
	t_2d_vector scaled_2ds[209];

	scale_coords_y(rotated_3ds, scaled_2ds);
	scale_coords_x(rotated_3ds, scaled_2ds);
	return (0);
}
