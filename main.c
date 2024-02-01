/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:55:13 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/01 23:50:44 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//FIX THIS JAWN VARIABLE

#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 1700

#include "fdf.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("===ERROR PARAM===\nPlease provide a single parameter containing relative path of your map file.\n");
		return (0);
	}
	t_data	data;
	t_mlx_shitter fmlx;

    ft_get_map(argv[1], &data);

	ft_rotate_45_z(&data);
    ft_rotate_beta_x(&data);
    ft_print_coords(&data);

    t_2d_vector scaled_2ds[data.num_of_pts];

	data.arr_of_2dcrds = scaled_2ds;

	/*
    printf("maxx is: %f\n", ft_fmaxx(rotated_3ds));
    printf("maxy is: %f\n", ft_fmaxy(rotated_3ds));
    printf("minx is: %f\n", ft_fminx(rotated_3ds));
    printf("miny is: %f\n", ft_fminy(rotated_3ds));
	*/

    scale_coords_y(&data);
    scale_coords_x(&data);

    ft_print_coords2(&data);

	printf("num of points = %d\n", data.num_of_pts);
	printf("BTW this jawn has %d points\n", data.num_of_pts);
    printf("Futhermore, this jawn has %d rows and %d columns\n", data.num_of_rows, data.num_of_cols);
	initialise_mlx(&data, &fmlx);
}
