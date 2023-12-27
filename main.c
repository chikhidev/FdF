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

void init_view(t_display *display, t_hooks *hooks, t_data *img)
{
	display->mlx = mlx_init();
	display->win = mlx_new_window(display->mlx, WIDTH, HEIGHT, WINDOW_NAME);
	img->img = mlx_new_image(display->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(
							img->img,
							&img->bits_per_pixel,
							&img->line_length,
							&img->endian);

	hooks->base_cartis->a = 1;
	hooks->base_cartis->b = 0;
	hooks->base_cartis->c = -1;
	hooks->base_cartis->d = 1;
	hooks->base_cartis->e = 0;
	hooks->base_cartis->f = -1;
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

	init_view(&display, &hooks, &img);

	(void)av;
	// *hooks.error = 0;
	// if (!get_matrix(&hooks, av[1], &hooks.grid))
	// {
	// 	write(2, "Error\n", 6);
	// 	return (1);
	// }

	draw_cartesian(&img, &hooks);
	
	t_point *cube_points = NULL;

	add_point(&cube_points, new_point(0, 0, 0));     // 1
	add_point(&cube_points, new_point(0, 0, 70));    // 2
	add_point(&cube_points, new_point(70, 0, 70));   // 3
	add_point(&cube_points, new_point(0, 70, 0));    // 5
	add_point(&cube_points, new_point(70, 70, 0));   // 8 (Changed order)
	add_point(&cube_points, new_point(70, 0, 0));    // 4 (Changed order)
	add_point(&cube_points, new_point(0, 70, 70));   // 6
	add_point(&cube_points, new_point(70, 70, 70));  // 7




    mark_points(&cube_points, &img, &hooks, WHITE_COLOR);
	

	
	mlx_put_image_to_window(
							display.mlx,
							display.win,
							img.img,
							0, 0);
	mlx_loop(display.mlx);
	return (0);
}

