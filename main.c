/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:15:08 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/11 03:31:39 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

void	exit_free(t_hooks *hooks)
{
	free_matrix(hooks->matrix, hooks);
	mlx_destroy_image(hooks->mlx, hooks->img.img);
	mlx_destroy_window(hooks->mlx, hooks->win);
	exit(0);
}

void	config_hooks(t_hooks *hooks)
{
	hooks->z_max = 0;
	hooks->z_min = 0;
	hooks->scale = .8;
	hooks->x_offset = 0;
	hooks->y_offset = 0;
	hooks->y_angle = 0;
	hooks->x_angle = 0;
	hooks->allow_link = 1;
	/*
		(1,0,0) → (a,b) (0,1,0) → (c,d) (0,0,1) → (e,f)
	*/
	hooks->base_cartis[0] = 1;		/*a*/
	hooks->base_cartis[1] = .333;	/*b*/
	
	hooks->base_cartis[2] = -1;		/*c*/
	hooks->base_cartis[3] = .333;	/*d*/
	
	hooks->base_cartis[4] = 0;		/*e*/
	hooks->base_cartis[5] = -1;		/*f*/
}

void refresh_image(t_hooks *hooks, t_data *img)
{
	img->img = mlx_new_image(hooks->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(
							img->img,
							&img->bits_per_pixel,
							&img->line_length,
							&img->endian
						);
	hooks->img = *img;
}

int	valid_extention(char	*name)
{
	char	*extention;

	extention = ft_strrchr(name, '.');
	if (!extention)
		return (0);
	return (ft_strncmp(extention, ".fdf", 4) == 0);
}

int main(int ac, char **av)
{
	t_data		img;
	t_hooks		hooks;

	if (ac != 2)
		return (print_error("Syntax error\nUsage: ./fdf FILE/PATH.fdf\n", 1));
	if (!valid_extention(av[1]))
		return (print_error("Invalid extention found, please use a .fdf file\n", 1));
	config_hooks(&hooks);
	hooks.z_factor = 30;
	if (!load_map(&hooks, av[1]))
		return (print_error("Map not loaded\n", 1));
	hooks.mlx = mlx_init();
	hooks.win = mlx_new_window(hooks.mlx, WIDTH, HEIGHT, WINDOW_NAME);
	refresh_image(&hooks, &img);
	mark_points(&hooks);
	mlx_put_image_to_window(
							hooks.mlx, hooks.win,
							img.img, 0, 0);
	mlx_hook(hooks.win, ON_MOUSEDOWN, 0, zoom_handle, &hooks);
	mlx_hook(hooks.win, ON_KEYDOWN, 0, key_listener, &hooks);
	show_guide(&hooks);
	mlx_loop(hooks.mlx);
	return (0);
}

