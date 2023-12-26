/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:16:05 by abchikhi          #+#    #+#             */
/*   Updated: 2023/12/25 16:28:33 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

/*
** put the pixel in the image
*/
void	put_the_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;
	
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_data *img, t_point *start, t_point *end)
{
	int	dx = end->x - start->x;
	int	dy = end->y - start->y;
	int	dz = end->z - start->z;
	int steps = (abs(dx) > abs(dy) ? abs(dx) : abs(dy));
	steps = (abs(dz) > abs(steps) ? abs(dz) : steps);

	float	x_increment = dx / (float)steps;
	float	y_increment = dy / (float)steps;
	float	z_increment = dz / (float)steps;
	
	float	x = start->x;
	float	y = start->y;
	float	z = start->z;

	int i = 0;
	while (i <= steps)
	{
		put_the_pixel(img, (int)x, (int)y + (int)z, 0xFFFFFF);
		// printf("\t<old>\t(%f, %f, %f)\n", x, y, z);
		x += (x_increment);
		y += (y_increment);
		z += (z_increment);
		// printf("\t<using>\t\t(%f, %f, %f)\n", x_increment, y_increment, z_increment);
		// printf("\t<updated>\t(%f, %f, %f)\n", x, y, z);
		i++;
	}
}

// void	generate_map(t_hooks *hooks, t_data *img)
// {

// }