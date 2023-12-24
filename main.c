/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:15:08 by abchikhi          #+#    #+#             */
/*   Updated: 2023/12/24 20:56:14 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

void init_view(t_display *display, t_data *img)
{
	display->mlx = mlx_init();
	display->win = mlx_new_window(display->mlx, WIDTH, HEIGHT, WINDOW_NAME);
	img->img = mlx_new_image(display->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(
							img->img,
							&img->bits_per_pixel,
							&img->line_length,
							&img->endian);
}


int main(int ag, char **av)
{
	t_display	display;
	t_data		img;
	t_hooks		hooks;

	if (ag != 2)
	{
		write(2, "Please use syntax:\n./fdf file.fdf\n", 35);
		return (1);
	}

	init_view(&display, &img);
	*hooks.error = 0;
	if (!get_matrix(&hooks, av[1], &hooks.grid))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	
	t_vector x_vector;
	x_vector.y = HEIGHT / 2;
	x_vector.z = 20;
	x_vector.x = (WIDTH / 2) - (x_vector.z / 2);
	//draw x axis
	draw_line(&img, &x_vector, 0xFFFFFF, DEFAULT_ANGLE);

	mlx_put_image_to_window(
							display.mlx,
							display.win,
							img.img,
							0, 0);
	mlx_loop(display.mlx);
	return (0);
}

