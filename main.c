/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:55:13 by fcharbon          #+#    #+#             */
/*   Updated: 2024/12/19 14:36:50 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 1700

#include "fdf.h"

void	initialise_and_adjust(t_data *data)
{
	int	i;

	i = 0;
	data->rc = 0;
	data->cc = 0;
	data->sc = 0;
	data->mapoffsety = ft_fmaxy(data) / 2;
	data->mapoffsetx = ft_fmaxx(data) / 2;
	data->pi_div_180 = 0.01745329251;
	data->arr_of_2dcrds = NULL;
	data->offset_x = 0;
	data->offset_y = 0;
	data->angular_offset_x = 0;
	data->angular_offset_z = 0;
	data->enable_top = 0;
	data->map_3dcrds = (t_3d_vector *)malloc(sizeof(t_3d_vector)
			* (data->num_of_pts));
	while (i < data->num_of_pts)
	{
		data->arr_of_3dcrds[i].x -= data->mapoffsetx;
		data->arr_of_3dcrds[i].y -= data->mapoffsety;
		data->arr_of_3dcrds[i].colour = colour_calculator(data,
				data->arr_of_3dcrds[i].z);
		i++;
	}
}

void	map_to_iso_px(t_data *data)
{
	copy_map_crds(data);
	ft_rotate_45_z(data);
	ft_rotate_beta_x(data);
	if (data->arr_of_2dcrds == NULL)
	{
		data->arr_of_2dcrds = (t_2d_vector *)malloc(sizeof(t_2d_vector)
				* (data->num_of_pts));
	}
	if (data->arr_of_2dcrds == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	scale_coords_y(data);
	scale_coords_x(data);
}

//WARNING! Feature is experimental! Proceed with caution!
void	map_to_sphere_px(t_data *data)
{
	copy_map_crds(data);
	if (data->arr_of_2dcrds == NULL)
	{
		data->arr_of_2dcrds = (t_2d_vector *)malloc(sizeof(t_2d_vector)
				* (data->num_of_pts));
	}
	if (data->arr_of_2dcrds == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	ft_rotate_sphere(data, 300);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("===ERROR PARAM===\nPlease provide a single parameter"
			" containing relative path of your map file.\n"
			"It should look a little something like this: "
			"./<executable> ./<map_file.fdf>\n");
		return (0);
	}
	data.map_path = argv[1];
	ft_get_map(argv[1], &data);
	// ft_print_coords(&data);	
	min_max_z(&data);
	initialise_and_adjust(&data);
	map_to_iso_px(&data);
	initialise_mlx(&data);
	return (0);
}
