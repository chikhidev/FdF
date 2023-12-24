/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:16:05 by abchikhi          #+#    #+#             */
/*   Updated: 2023/12/24 20:42:28 by abchikhi         ###   ########.fr       */
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

/*
* draw a line from the point (x, y) to the point (x, y + z)
*/
void	draw_line(t_data *img, t_vector *vector, int color, int angle)
{
	int		i;
	int		j;
	int		k;
	int		x;
	int		y;

	i = 0;
	j = 0;
	k = 0;
	x = vector->x;
	y = vector->y;
	while (i < vector->z)
	{
		while (j < angle)
		{
			put_the_pixel(img, x, y, color);
			x++;
			j++;
		}
		j = 0;
		i++;
		y++;
	}
}
