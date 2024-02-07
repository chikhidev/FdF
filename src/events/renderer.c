/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:01:13 by abchikhi          #+#    #+#             */
/*   Updated: 2024/02/06 20:48:55 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./events_bonus.h"
#include "../includes/extra.h"

int	render_next_frame(t_hooks *hooks)
{
	mlx_destroy_image(hooks->mlx, hooks->img.img);
	refresh_image(hooks, &hooks->img);
	draw_background(hooks);
	mark_points(hooks);
	mlx_put_image_to_window(
		hooks->mlx, hooks->win, hooks->img.img, 0, 0);
	show_guide(hooks);
	return (0);
}
