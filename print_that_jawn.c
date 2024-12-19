/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_that_jawn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:38:01 by fcharbon          #+#    #+#             */
/*   Updated: 2024/12/19 14:36:56 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_coords3(t_data *data)
{
	int	count;

	count = -1;
	printf("START OF MAP COORDS\n\n\n\n\n");
	while (count < data->num_of_pts)
	{
		printf("This is coordinate %d. (%.5f, %.5f, %.5f)\n", count,
			data->map_3dcrds[count].x, data->map_3dcrds[count].y,
			data->map_3dcrds[count].z);
		count++;
	}
}

void	ft_print_coords(t_data *data)
{
	int	count;

	count = 0;
	printf("START OF 3D COORDS\n\n\n\n\n");
	while (count < data->num_of_pts)
	{
		printf("This is coordinate %d. (%.5f, %.5f, %.5f)\n",
			count,
			data->arr_of_3dcrds[count].x, data->arr_of_3dcrds[count].y,
			data->arr_of_3dcrds[count].z/*, data->arr_of_3dcrds[count].colour*/);
		count++;
	}
}

void	ft_print_coords2(t_data *data)
{
	int	count;

	count = 0;
	printf("START OF NEW COORDS\n\n\n\n\n");
	while (count < data->num_of_pts)
	{
		printf("This is 2D coordinate %d. (%.5f, %.5f)\n", count,
			data->arr_of_2dcrds[count].x, data->arr_of_2dcrds[count].y);
		count++;
	}
	printf("BTW this jawn has %d points", data->num_of_pts);
	printf("Futhermore, this jawn has %d rows and %d columns",
		data->num_of_rows, data->num_of_cols);
}
