/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:28:58 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/28 00:28:12 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./events/events_bonus.h"
#include "./includes/header_bonus.h"

void	center_map(t_hooks *hooks)
{
	t_map_edges	edges;

	edges.left.x = 0;
	edges.left.y = hooks->height_grid * hooks->y_factor;
	edges.left.z = get_z(hooks->matrix[hooks->height_grid - 1][0], hooks);
	edges.right.x = hooks->width_grid * hooks->x_factor;
	edges.right.y = 0;
	edges.right.z = get_z(hooks->matrix[0][hooks->width_grid - 1], hooks);
	edges.top.x = 0;
	edges.top.y = 0;
	edges.top.z = get_z(hooks->matrix[0][0], hooks);
	edges.bottom.x = hooks->width_grid * hooks->x_factor;
	edges.bottom.y = hooks->height_grid * hooks->y_factor;
	edges.bottom.z = get_z(hooks->matrix[hooks->height_grid
			- 1][hooks->width_grid - 1], hooks);
	get_real_point(hooks, &edges.left);
	get_real_point(hooks, &edges.right);
	get_real_point(hooks, &edges.top);
	get_real_point(hooks, &edges.bottom);
	hooks->x_offset = (WIDTH / 2) - (edges.left.x + edges.right.x) / 2;
	hooks->y_offset = (HEIGHT / 2) - (edges.top.y + edges.bottom.y) / 2;
}

int	is_center_point(t_hooks *hooks, int i, int j)
{
	if (hooks->width_grid % 2 == 0 && hooks->height_grid % 2 == 0)
		return (i == hooks->height_grid / 2 && j == hooks->width_grid / 2 - 1);
	else if (hooks->height_grid % 2 == 0 && hooks->width_grid % 2 != 0)
		return (i == hooks->height_grid / 2 && j == (hooks->width_grid / 2
				- 1));
	else if (hooks->height_grid % 2 != 0 && hooks->width_grid % 2 == 0)
		return (i == hooks->height_grid / 2 - 1 && j == hooks->width_grid / 2);
	return (i == hooks->height_grid / 2 - 1 && j == hooks->width_grid / 2 - 1);
}

void	choose_render_direction(t_hooks *hooks)
{
	int	az;

	az = (int)hooks->z_angle;
	if ((az >= 0 && az < 45) || (az > 315 && az < 360) || az == 45)
		render_top_left(hooks);
	else if ((az > 45 && az < 90))
		render_bottom_left(hooks);
	else if ((az >= 90 && az < 225) || az == 225)
		render_bottom_right(hooks);
	else if (az > 225 && az < 315)
		render_top_right(hooks);
}

void	get_center_point(t_hooks *hooks)
{
	int	dz;

	hooks->center_point.x = hooks->width_grid / 2 * hooks->x_factor;
	hooks->center_point.y = hooks->height_grid / 2 * hooks->y_factor;
	if (hooks->z_max > hooks->z_min)
		dz = hooks->z_max - hooks->z_min;
	else
		dz = hooks->z_min - hooks->z_max;
	hooks->center_point.z = (dz / 2) * hooks->z_factor;
}

void	mark_points(t_hooks *hooks)
{
	int		i;
	int		j;
	t_point	point;

	choose_render_direction(hooks);
	get_center_point(hooks);
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
			if (hooks->allow_link)
				link_point(hooks, i, j);
			j += hooks->direction.j_step;
		}
		i += hooks->direction.i_step;
	}
}
