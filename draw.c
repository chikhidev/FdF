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

void draw_line(t_data *img, t_hooks *hooks, t_point *start, t_point *end, int color)
{
	int	x;
	int	y;
	int	z;

	x = start->x;
	y = start->y;
	z = start->z;
    while (1)
	{
		if (x == end->x && y == end->y && z == end->z)
			break ;
		if (x != end->x)
			x > end->x ? x-- : x++;
		if (y != end->y)
			y > end->y ? y-- : y++;
		if (z != end->z)
			z > end->z ? z-- : z++;
		cartesian(img, hooks, x, y, z, color);
	}
}
