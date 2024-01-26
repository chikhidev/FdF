/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:04:29 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/26 22:23:58 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

void	_setup_(t_hooks *hooks)
{
	hooks->width_grid = 0;
	hooks->height_grid = 0;
	hooks->z_max = 0;
	hooks->z_min = 0;
}

void	config_hooks(t_hooks *hooks)
{
	hooks->scale = .3;
	hooks->x_offset = 0;
	hooks->y_offset = 0;
	hooks->x_factor = 0;
	hooks->y_factor = 0;
}

void	refresh_image(t_hooks *hooks, t_data *img)
{
	img->img = mlx_new_image(hooks->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(
			img->img,
			&img->bits_per_pixel,
			&img->line_length,
			&img->endian);
	hooks->img = *img;
}
