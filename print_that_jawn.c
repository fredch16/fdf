/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_that_jawn.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:38:01 by fcharbon          #+#    #+#             */
/*   Updated: 2024/01/31 19:48:31 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_coords(t_data *data)
{
	int	count;

	count = 0;
	printf("START OF NEW COORDS\n\n\n\n\n");
	while(count < data->num_of_pts)
	{
		printf("This is coordinate %d. (%.5f, %.5f, %.5f)\n", count,
				data->arr_of_3dcrds[count].x, data->arr_of_3dcrds[count].y, data->arr_of_3dcrds[count].z);
		count++;
	}
}

void	ft_print_coords2(t_data *data)
{
	int	count;

	count = 0;
	printf("START OF NEW COORDS\n\n\n\n\n");
	while(count < data->num_of_pts)
	{
		printf("This is scaled coordinate %d. (%.5f, %.5f)\n", count,
				data->arr_of_2dcrds[count].x, data->arr_of_2dcrds[count].y);
		count++;
	}
	printf("BTW this jawn has %d points", data->num_of_pts);
	printf("Futhermore, this jawn has %d rows and %d columns", data->num_of_rows, data->num_of_cols);
}
