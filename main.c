/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:15:08 by abchikhi          #+#    #+#             */
/*   Updated: 2023/12/25 16:02:45 by abchikhi         ###   ########.fr       */
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

	draw_cartesian_axis(&img);
	// generate_map(&hooks, &img);
	// t_point p1;
	// t_point p2;
	
	// p1.x = 5;
	// p1.y = 2;
	// p1.z = 90;

	// p2.x = 542;
	// p2.y = 845;
	// p2.z = 0;
	// draw_line(&img, &p1, &p2);
	// put_the_pixel(&img, p2.x, p2.y, 0xFFFF00);
	// put_the_pixel(&img, p1.x, p1.y, 0xFFFF00);

	mlx_put_image_to_window(
							display.mlx,
							display.win,
							img.img,
							0, 0);
	mlx_loop(display.mlx);
	return (0);
}

