/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:03:07 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/28 00:39:31 by abchikhi         ###   ########.fr       */
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

void	get_real_point(t_hooks *hooks, t_point *point)
{
	int		real_x;
	double	iso_angle;

	iso_angle = 30 * M_PI / 180;
	real_x = hooks->scale * (point->x - point->y) * cos(iso_angle);
	point->y = hooks->scale * ((point->x + point->y - point->z) * sin(iso_angle)
			- point->z);
	point->x = real_x + hooks->x_offset;
	point->y += hooks->y_offset;
}
