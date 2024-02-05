/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_in_3D.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:44:28 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/05 13:59:02 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define PIBY4 0.78539816339
#define R3O3 0.57735026919
#define R6O3 0.81649658092

void	ft_rotate_45_z(t_data *data)
{
	int		count;
	double	tempx;

	count = 0;
	while (count < data->num_of_pts)
	{
		tempx = data->arr_of_3dcrds[count].x;
		data->arr_of_3dcrds[count].x = tempx * cos(PIBY4) + data->arr_of_3dcrds[count].y * sin(PIBY4);
		data->arr_of_3dcrds[count].y = tempx * -sin(PIBY4) + data->arr_of_3dcrds[count].y * cos(PIBY4);
		count++;
	}
}

void	ft_rotate_beta_x(t_data *data)
{
	int		count;
	double	tempy;

	count = 0;
	while (count < data->num_of_pts)
	{
		tempy = data->arr_of_3dcrds[count].y;
		data->arr_of_3dcrds[count].y = tempy * R3O3 + data->arr_of_3dcrds[count].z * R6O3;
		data->arr_of_3dcrds[count].z = tempy * -R6O3 + data->arr_of_3dcrds[count].z * R3O3;
		count++;
	}
}
