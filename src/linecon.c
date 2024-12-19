/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linecon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:22:03 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/11 22:32:54 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	connect_right(t_data *data, int index)
{
	data->x0 = data->arr_of_2dcrds[index].x;
	data->y0 = data->arr_of_2dcrds[index].y;
	data->x1 = data->arr_of_2dcrds[index + 1].x;
	data->y1 = data->arr_of_2dcrds[index + 1].y;
	data->startcol = data->arr_of_2dcrds[index].colour;
	data->endcol = data->arr_of_2dcrds[index + 1].colour;
	ft_putline(data);
}

void	connect_left(t_data *data, int index)
{
	int			offset;

	offset = data->num_of_rows - 1;
	data->x0 = data->arr_of_2dcrds[index].x;
	data->y0 = data->arr_of_2dcrds[index].y;
	data->x1 = data->arr_of_2dcrds[index - offset].x;
	data->y1 = data->arr_of_2dcrds[index - offset].y;
	data->startcol = data->arr_of_2dcrds[index].colour;
	data->endcol = data->arr_of_2dcrds[index - offset].colour;
	ft_putline(data);
}

void	connect_down(t_data *data, int index)
{
	int			offset;

	offset = data->num_of_cols;
	data->x0 = data->arr_of_2dcrds[index].x;
	data->y0 = data->arr_of_2dcrds[index].y;
	data->x1 = data->arr_of_2dcrds[index + offset].x;
	data->y1 = data->arr_of_2dcrds[index + offset].y;
	data->startcol = data->arr_of_2dcrds[index].colour;
	data->endcol = data->arr_of_2dcrds[index + offset].colour;
	ft_putline(data);
}

void	line_looper(t_data *data)
{
	while (data->rc < data->num_of_rows)
	{
		while (data->cc < data->num_of_cols)
		{
			if (!(data->cc == data->num_of_cols - 1)
				&& !(data->rc == data->num_of_rows - 1))
			{
				connect_right(data, data->sc);
				connect_down(data, data->sc);
			}
			else if (!(data->rc == data->num_of_rows - 1))
			{
				connect_down(data, data->sc);
			}
			else if (!(data->cc == data->num_of_cols - 1))
				connect_right(data, data->sc);
			data->cc++;
			data->sc++;
		}
		data->cc = 0;
		data->rc++;
	}
}
