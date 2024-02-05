/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:55:13 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/05 21:43:27 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//FIX THIS JAWN VARIABLE

#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 1700

#include "fdf.h"

//void	map_to_coords(t_data *data)

void	map_to_3d(t_data *data, char *mapname)
{
	ft_get_map(mapname, data);
	ft_rotate_45_z(data);
    ft_rotate_beta_x(data);
    ft_print_coords(data);
	data->offset_x = 0;
	data->offset_y = 0;
}

void	threed_to_pxpts(t_data *data)
{

	data->arr_of_2dcrds = (t_2d_vector *)malloc(sizeof(t_2d_vector) * (data->num_of_pts));
	if (data->arr_of_2dcrds == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
    scale_coords_y(data);
    scale_coords_x(data);
	free_arr_of_3dcrds(data);
    ft_print_coords2(data);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("===ERROR PARAM===\nPlease provide a single parameter"
				" containing relative path of your map file.\n"
				"It should look a little something like this: "
				"./<executable> ./<map_file.fdf>\n");
		return (0);
	}
	t_data	data;
	t_mlx_shitter fmlx;
	map_to_3d(&data, argv[1]);
	threed_to_pxpts(&data);
	/*
    printf("maxx is: %f\n", ft_fmaxx(rotated_3ds));
    printf("maxy is: %f\n", ft_fmaxy(rotated_3ds));
    printf("minx is: %f\n", ft_fminx(rotated_3ds));
    printf("miny is: %f\n", ft_fminy(rotated_3ds));
	*/
	printf("num of points = %d\n", data.num_of_pts);
	printf("BTW this jawn has %d points\n", data.num_of_pts);
    printf("Futhermore, this jawn has %d rows and %d columns\n", data.num_of_rows, data.num_of_cols);
	initialise_mlx(&data, &fmlx);
	return (0);
}
