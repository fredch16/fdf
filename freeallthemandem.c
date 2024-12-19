/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeallthemandem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:11:52 by fcharbon          #+#    #+#             */
/*   Updated: 2024/02/12 17:45:06 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_arr_of_3dcrds(t_data *data)
{
	if (data != NULL && data->arr_of_3dcrds != NULL)
	{
		free(data->arr_of_3dcrds);
		data->arr_of_3dcrds = NULL;
	}
}

void	free_arr_of_2dcrds(t_data *data)
{
	if (data != NULL && data->arr_of_2dcrds != NULL)
	{
		free(data->arr_of_2dcrds);
		data->arr_of_2dcrds = NULL;
	}
}

void	free_map_3dcrds(t_data *data)
{
	if (data != NULL && data->map_3dcrds != NULL)
	{
		free(data->map_3dcrds);
		data->map_3dcrds = NULL;
	}
}
