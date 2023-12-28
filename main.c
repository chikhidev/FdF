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
	/*(1,0,0) → (a,b) (0,1,0) → (c,d) (0,0,1) → (e,f)*/
	hooks->base_cartis[0] = 1;	/*a*/
	hooks->base_cartis[1] = 0;	/*b*/
	hooks->base_cartis[2] = -1;	/*c*/
	hooks->base_cartis[3] = 1;	/*d*/
	hooks->base_cartis[4] = 0;	/*e*/
	hooks->base_cartis[5] = -1;	/*f*/
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
	if (!get_matrix(&hooks, av[1], &hooks.grid))
		return (1);

	draw_cartesian(&img, &hooks);
	
	/*left rotation x axis*/
	// hooks.base_cartis[2] = .5;
	
	free_matrix(&hooks);
	mlx_put_image_to_window(
							display.mlx,
							display.win,
							img.img,
							0, 0);
	mlx_loop(display.mlx);
	return (0);
}

