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

void init(t_display *display, t_hooks *hooks, t_data *img)
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
	hooks->base_cartis[0] = 1;		/*a*/
	hooks->base_cartis[1] = 0;		/*b*/
	hooks->base_cartis[2] = -.5;	/*c*/
	hooks->base_cartis[3] = .3;		/*d*/
	hooks->base_cartis[4] = 0;		/*e*/
	hooks->base_cartis[5] = -0.1;	/*f*/
}

int	valid_extention(char	*name)
{
	char	*extention;

	extention = ft_strrchr(name, '.');
	if (!extention)
		return (0);
	return (ft_strncmp(extention, ".fdf", 4) == 0);
}

void display_loading_screen(t_display *display, t_data *img) {
    mlx_string_put(display->mlx, display->win, 50, 50, 0xFFFFFF, "Loading...");
    mlx_put_image_to_window(display->mlx, display->win, img->img, 0, 0);
}

void remove_loading_screen(t_display *display, t_data *img) {
    mlx_clear_window(display->mlx, display->win);
    mlx_put_image_to_window(display->mlx, display->win, img->img, 0, 0);
}

int main(int ac, char **av)
{
	t_display	display;
	t_data		img;
	t_hooks		hooks;

	if (ac != 2)
		return (print_error("Syntax error\nUsage: ./fdf FILE/PATH.fdf\n", 1));
	if (!valid_extention(av[1]))
		return (print_error("Invalid extention found, please use a .fdf file\n", 1));
	if (!load_map(&hooks, av[1], &hooks.grid))
		return (print_error("Map not loaded\n", 1));
	init(&display, &hooks, &img);
	draw_cartesian(&img, &hooks);
	
	display_loading_screen(&display, &img);

	mark_points(&hooks.space_points, &img, &hooks);

	remove_loading_screen(&display, &img);
	/*left rotation x axis*/
	// hooks.base_cartis[2] = .5;
	
	mlx_put_image_to_window(
							display.mlx,
							display.win,
							img.img,
							0, 0);
	mlx_loop(display.mlx);
	return (0);
}

