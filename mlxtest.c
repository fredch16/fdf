/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:07:44 by fcharbon          #+#    #+#             */
/*   Updated: 2024/01/09 19:07:14 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "mlx_linux/mlx.h"
#include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void drawCircle(int x, int y, int r, int colour, t_data img)
{
	static const double PI = 3.1415926535;
	double i, angle, x1, y1;

	for (i = 0; i < 360; i += 0.1)
	{
		angle = i;
		x1 = r * cos(angle * PI / 180);
		y1 = r * sin(angle * PI / 180);
		my_mlx_pixel_put(&img, x + x1, y + y1, colour);
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		i;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "MARS");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	drawCircle(960, 540, 339, 0x00FF0000, img);
	//drawCircle(960, 540, 421, 0x00780808, img);

	x = 0;
	y = 0;
	i = 0;
	while (i < 1000)
	{
		my_mlx_pixel_put(&img, x + i, y + i, 0x00AF0123);
		i++;
	}
	x = 1000;
	y = 1000;
	i = 0;
	while (i < 920)
	{
		my_mlx_pixel_put(&img, x + i, y - i, 0x00AA999);
		i++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
