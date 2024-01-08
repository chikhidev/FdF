/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:15:08 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/08 20:54:35 by abchikhi         ###   ########.fr       */
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
							&img->endian
						);
	/*
		(1,0,0) → (a,b) (0,1,0) → (c,d) (0,0,1) → (e,f)
	*/
	hooks->base_cartis[0] = 1;		/*a*/
	hooks->base_cartis[1] = .3;		/*b*/
	hooks->base_cartis[2] = -1;		/*c*/
	hooks->base_cartis[3] = .3;		/*d*/
	hooks->base_cartis[4] = 0;		/*e*/
	hooks->base_cartis[5] = -.5;	/*f*/
}

int	valid_extention(char	*name)
{
	char	*extention;

	extention = ft_strrchr(name, '.');
	if (!extention)
		return (0);
	return (ft_strncmp(extention, ".fdf", 4) == 0);
}

int handler2(int x, int y, void *test)
{
	(void)test;
	printf("%d %d\n", x, y);
	return (0);
}

int handler(int button, int x, int y, t_display *display)
{
	(void)button;
	(void)x;
	(void)y;
	if (button == 2)
		mlx_hook(display->win, 6, 0, handler2, NULL);
	//printf("%d %d\n", x, y);
	return (0);
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
	mark_points(&img, &hooks);

	/*left rotation x axis*/
	// hooks.base_cartis[2] = .5;
	mlx_put_image_to_window(
							display.mlx,
							display.win,
							img.img,
							0, 0);
	mlx_hook(display.win, 4, 0, handler, &display);
	mlx_loop(display.mlx);
	return (0);
}

