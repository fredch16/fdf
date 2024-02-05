/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linecon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:22:03 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/05 13:43:27 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 	line_looper(t_data *data, t_mlx_shitter *fmlx)
{
	int	rc;
	int	cc;
	int sc;

	rc = 0;
	cc = 0;
	sc = 0;
	printf("\n\n\n\n\n THIS IS BEGIN OF LINE LOOPER \n\n\n\n\n");
	while (rc < data->num_of_rows)
	{
		while (cc < data->num_of_cols)
		{
			if (!(cc == data->num_of_cols - 1) && !(rc == data->num_of_rows - 1))
			{
				connect_right(data, sc, fmlx);
				connect_down(data, sc, fmlx);
			}
			else if (!(rc == data->num_of_rows - 1))
				connect_down(data, sc, fmlx);
			else if (!(cc == data->num_of_cols -1))
				connect_right(data, sc, fmlx);
			cc++;
			sc++;
		}
		cc = 0;
		rc++;
	}
}

void	connect_right(t_data *data, int index, t_mlx_shitter *fmlx)
{

	fmlx->x0 = data->arr_of_2dcrds[index].x;
	fmlx->y0 = data->arr_of_2dcrds[index].y;
	fmlx->x1 = data->arr_of_2dcrds[index + 1].x;
	fmlx->y1 = data->arr_of_2dcrds[index + 1].y;
	ft_putline(fmlx);
	printf("Connected right %d/%d\n", index, data->num_of_pts -2);
}

void    connect_down(t_data *data, int index, t_mlx_shitter *fmlx)
{
	int			offset;

	offset = data->num_of_cols;

	fmlx->x0 = data->arr_of_2dcrds[index].x;
	fmlx->y0 = data->arr_of_2dcrds[index].y;
	fmlx->x1 = data->arr_of_2dcrds[index + offset].x;
	fmlx->y1 = data->arr_of_2dcrds[index + offset].y;
	ft_putline(fmlx);
	printf("Connected down %d/%d\n", index, data->num_of_pts -2);
}
