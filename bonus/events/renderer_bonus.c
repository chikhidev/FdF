/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:01:13 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/26 15:51:34 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./events_bonus.h"

int	render_next_frame(t_hooks *hooks)
{
	mlx_destroy_image(hooks->mlx, hooks->img.img);
	refresh_image(hooks, &hooks->img);
	mark_points(hooks);
	mlx_put_image_to_window(
		hooks->mlx, hooks->win, hooks->img.img, 0, 0);
	show_guide(hooks);
	return (0);
}
