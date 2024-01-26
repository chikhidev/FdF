/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:28:58 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/26 08:36:40 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

void	center_map(t_hooks *hooks)
{
	t_point	left;
	t_point	right;
	t_point	top;
	t_point	bottom;

	left.x = 0;
	left.y = hooks->height_grid * hooks->y_factor;
	left.z = get_z(hooks->matrix[hooks->height_grid - 1][0], hooks);
	right.x = hooks->width_grid * hooks->x_factor;
	right.y = 0;
	right.z = get_z(hooks->matrix[0][hooks->width_grid - 1], hooks);
	top.x = 0;
	top.y = 0;
	top.z = get_z(hooks->matrix[0][0], hooks);
	bottom.x = hooks->width_grid * hooks->x_factor;
	bottom.y = hooks->height_grid * hooks->y_factor;
	bottom.z = get_z(hooks->matrix[hooks->height_grid - 1][hooks->width_grid
			- 1], hooks);
	get_real_point(hooks, &left);
	get_real_point(hooks, &right);
	get_real_point(hooks, &top);
	get_real_point(hooks, &bottom);
	hooks->x_offset = (WIDTH / 2) - (left.x + right.x) / 2;
	hooks->y_offset = (HEIGHT / 2) - (top.y + bottom.y) / 2;
}

void	choose_render_direction(t_hooks *hooks)
{
	hooks->direction.i_start = 0;
	hooks->direction.i_end = hooks->height_grid;
	hooks->direction.i_step = 1;
	hooks->direction.j_start = 0;
	hooks->direction.j_end = hooks->width_grid;
	hooks->direction.j_step = 1;
}

void	mark_points(t_hooks *hooks)
{
	int		i;
	int		j;
	t_point	point;

	choose_render_direction(hooks);
	i = hooks->direction.i_start;
	while ((i < hooks->direction.i_end && hooks->direction.i_step == 1)
		|| (i > hooks->direction.i_end && hooks->direction.i_step == -1))
	{
		j = hooks->direction.j_start;
		while ((j < hooks->direction.j_end && hooks->direction.j_step == 1)
			|| (j > hooks->direction.j_end && hooks->direction.j_step == -1))
		{
			init_point(hooks, &point, i, j);
			get_real_point(hooks, &point);
			put_the_pixel(&hooks->img, point.x, point.y, point.color);
			link_point(hooks, i, j);
			j += hooks->direction.j_step;
		}
		i += hooks->direction.i_step;
	}
}
