/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:15:08 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/28 00:30:45 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header_bonus.h"
#include "events/events_bonus.h"

int	main(int ac, char **av)
{
	t_data	img;
	t_hooks	hooks;

	if (ac != 2)
		return (print_error("Syntax error\nUsage: ./fdf FILE/PATH.fdf\n", 1));
	if (!valid_extention(av[1]))
		return (print_error("Invalid extention found\n", 1));
	_setup_(&hooks);
	config_hooks(&hooks);
	hooks.z_factor = 30;
	load_map(&hooks, av[1]);
	hooks.mlx = mlx_init();
	refresh_image(&hooks, &img);
	center_map(&hooks);
	hooks.win = mlx_new_window(hooks.mlx, WIDTH, HEIGHT, WINDOW_NAME);
	mark_points(&hooks);
	mlx_put_image_to_window(hooks.mlx, hooks.win, img.img, 0, 0);
	mlx_hook(hooks.win, ON_DESTROY, 0, destroy, &hooks);
	mlx_hook(hooks.win, ON_KEYDOWN, 0, event_listener, &hooks);
	show_guide(&hooks);
	mlx_loop(hooks.mlx);
	return (0);
}
