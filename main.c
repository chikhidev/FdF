/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:15:08 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/14 17:37:12 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

int	close_win(int keycode, t_hooks *hooks)
{
	if (keycode == 53)
	{
		ft_printf("Bye\n");
		exit_free(hooks);
	}
	ft_printf("key is : %d\n", keycode);
	return (0);
}

int main(int ac, char **av)
{
	t_data		img;
	t_hooks		hooks;

	if (ac != 2)
		print_error("Syntax error\nUsage: ./fdf FILE/PATH.fdf\n", 1);
	if (!valid_extention(av[1]))
		print_error("Invalid extention found, please use a .fdf file\n", 1);
	config_hooks(&hooks);
	hooks.z_factor = 50;
	load_map(&hooks, av[1]);
	hooks.mlx = mlx_init();
	hooks.win = mlx_new_window(hooks.mlx, WIDTH, HEIGHT, WINDOW_NAME);
	refresh_image(&hooks, &img);
	mark_points(&hooks);
	mlx_put_image_to_window(
							hooks.mlx, hooks.win,
							img.img, 0, 0);
	mlx_hook(hooks.win, ON_DESTROY, 0, destroy, &hooks);
	mlx_hook(hooks.win, ON_KEYDOWN, 0, close_win, &hooks);
	mlx_loop(hooks.mlx);
	return (0);
}
