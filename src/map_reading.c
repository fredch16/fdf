/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:43:42 by fcharbon          #+#    #+#             */
/*   Updated: 2024/03/27 17:56:43 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	**ft_get_map_lines(int map_fd)
{
	char	*gnl_ret;
	char	*str;
	char	*tofree;
	char	**map_lines;

	gnl_ret = get_next_line(map_fd);
	if (!gnl_ret)
		return (NULL);
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (gnl_ret)
	{
		tofree = str;
		str = ft_strjoin(str, gnl_ret);
		if (!str)
			return (free(gnl_ret), free(tofree), NULL);
		free(tofree);
		gnl_ret = (free(gnl_ret), get_next_line(map_fd));
	}
	map_lines = ft_split(str, '\n');
	if (!map_lines)
		return (free(str), NULL);
	return (free(str), map_lines);
}

char	***ft_mapline_to_strvalue(char **map_lines)
{
	size_t	i;
	char	***map_str_vals;

	map_str_vals = (char ***)ft_calloc(
			(ft_strs_len(map_lines) + 1), sizeof(char **));
	if (!map_str_vals)
		return (ft_free_char2(map_lines), NULL);
	i = 0;
	while (map_lines[i])
	{
		map_str_vals[i] = ft_split(map_lines[i], ' ');
		if (!map_str_vals[i])
			return (ft_free_char3(map_str_vals),
				ft_free_char2(map_lines), NULL);
		i++;
	}
	return (ft_free_char2(map_lines), map_str_vals);
}

void	char_arr_len(char ***map_vals, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_vals[i])
		i++;
	while (map_vals[0][j])
		j++;
	data->num_of_pts = i * j;
	data->num_of_rows = i;
	data->num_of_cols = j;
}

void	ft_strval_to_3dvect(char ***map_str_vals, t_data *data)
{
	int			i;
	int			j;
	int			count;

	char_arr_len(map_str_vals, data);
	count = 0;
	data->arr_of_3dcrds = (t_3d_vector *)malloc(sizeof(t_3d_vector)
			* (data->num_of_pts));
	i = 0;
	while (map_str_vals[i])
	{
		j = 0;
		while (map_str_vals[i][j])
		{
			data->arr_of_3dcrds[count].x = (double)j;
			data->arr_of_3dcrds[count].y = (double)i;
			data->arr_of_3dcrds[count].z = (double)-ft_atoi(map_str_vals[i][j]);
			j++;
			count++;
		}
		i++;
	}
	ft_free_char3(map_str_vals);
}

void	ft_get_map(char *map_path, t_data *data)
{
	int	map_fd;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd < 0)
	{
		perror("Error opening file");
		if (errno == ENOENT)
			ft_printf("File does not exist: %s\n", map_path);
		else if (errno == EACCES)
			ft_printf("Please change access permissions for file: %s\n",
				map_path);
		exit(EXIT_FAILURE);
	}
	ft_strval_to_3dvect(ft_mapline_to_strvalue(ft_get_map_lines(map_fd)), data);
}
