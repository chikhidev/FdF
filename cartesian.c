/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:03:07 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/25 13:06:15 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

void	init_point(t_hooks *hooks, t_point *point, int row, int col)
{
	point->x = col * hooks->x_factor;
	point->y = row * hooks->y_factor;
	point->z = get_z(hooks->matrix[row][col], hooks);
	point->color = get_color(hooks->matrix[row][col], hooks);
}

void	extract(t_hooks *hooks, t_point *point)
{
	t_point	temp;
	double	az;

	az = hooks->z_angle * (M_PI / 180);
	temp.x = (point->x - hooks->center_point.x) * cos(az)
		- (point->y - hooks->center_point.y) * sin(az)
		+ hooks->center_point.x;
	temp.y = (point->x - hooks->center_point.x) * sin(az)
		+ (point->y - hooks->center_point.y) * cos(az)
		+ hooks->center_point.y;
	point->x = temp.x;
	point->y = temp.y;
}

void	get_real_point(t_hooks *hooks, t_point *point)
{
	int	real_x;

	extract(hooks, point);
	if (hooks->parallel_view)
	{
		real_x = hooks->scale * (point->x - hooks->center_point.x)
			+ hooks->x_offset;
		point->y = hooks->scale * (point->y - hooks->center_point.y)
			+ hooks->y_offset;
		point->x = real_x;
		return ;
	}
	real_x = hooks->scale * (point->x - point->y) + hooks->x_offset;
	point->y = hooks->scale * (point->x + point->y - point->z)
		+ hooks->y_offset;
	point->x = real_x;
}
