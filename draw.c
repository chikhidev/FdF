/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:16:05 by abchikhi          #+#    #+#             */
/*   Updated: 2023/12/24 14:13:04 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

/*
** put the pixel in the image
*/
void	put_the_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	push_angle(t_vector *vector, int angle)
{
	vector->x = vector->x * cos(angle) - vector->y * sin(angle);
	vector->y = vector->x * sin(angle) + vector->y * cos(angle);
}

/*
* draw a line from the point (x, y) to the point (x, y + z)
*/
void	x_axis_line(t_data *img, t_vector *vector, int color)
{
	while (vector->x < WIDTH)
	{
		put_the_pixel(img, vector->x, vector->y, color);
		push_angle(vector, 40);
		vector->x++;
	}
}