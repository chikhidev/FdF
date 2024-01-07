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

void draw_line(t_data *img, t_hooks *hooks, t_point *start, t_point *end, int color) {
    int x1 = start->x, y1 = start->y, z1 = start->z;
    int x2 = end->x, y2 = end->y, z2 = end->z;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int dz = abs(z2 - z1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int sz = (z1 < z2) ? 1 : -1;

    int err1, err2;

    if (dx >= dy && dx >= dz) {
        err1 = dy - (dx >> 1);
        err2 = dz - (dx >> 1);

        while (x1 != x2) {
            cartesian(img, hooks, x1, y1, z1, color);

            if (err1 >= 0) {
                y1 += sy;
                err1 -= dx;
            }

            if (err2 >= 0) {
                z1 += sz;
                err2 -= dx;
            }

            x1 += sx;
            err1 += dy;
            err2 += dz;
        }
    } else if (dy >= dx && dy >= dz) {
        err1 = dx - (dy >> 1);
        err2 = dz - (dy >> 1);

        while (y1 != y2) {
            cartesian(img, hooks, x1, y1, z1, color);

            if (err1 >= 0) {
                x1 += sx;
                err1 -= dy;
            }

            if (err2 >= 0) {
                z1 += sz;
                err2 -= dy;
            }

            y1 += sy;
            err1 += dx;
            err2 += dz;
        }
    } else {
        err1 = dy - (dz >> 1);
        err2 = dx - (dz >> 1);

        while (z1 != z2) {
            cartesian(img, hooks, x1, y1, z1, color);

            if (err1 >= 0) {
                y1 += sy;
                err1 -= dz;
            }

            if (err2 >= 0) {
                x1 += sx;
                err2 -= dz;
            }

            z1 += sz;
            err1 += dy;
            err2 += dx;
        }
    }

    cartesian(img, hooks, x2, y2, z2, color); // Ensure the last point is drawn
}

// void draw_line(t_data *img, t_hooks *hooks, t_point *start, t_point *end, int color)
// {
// 	int	x;
// 	int	y;
// 	int	z;
// 	double	steps[3]; /*x, y, z*/
// 	int		drct[3];
	
// 	drct[0] = end->x - start->x;
// 	steps[0] = (drct[0] != 0 ? end->x / abs(drct[0]) : 0);

// 	drct[1] = end->y - start->y;
// 	steps[1] = (drct[1] != 0 ? end->y / abs(drct[1]) : 0);

// 	drct[2] = end->z - start->z;
// 	steps[2] = (drct[2] != 0 ? end->z / abs(drct[2]) : 0);

// 	printf("steps needed are (%lf for x, %lf for y, %lf for z)\n", 
// 		steps[0], steps[1], steps[2]);
// 	x = start->x;
// 	y = start->y;
// 	z = start->z;
// 	printf("linking from (%d, %d, %d) to (%d, %d, %d)\n\n\n",
// 		x, y, z, end->x, end->y, end->z
// 	);
//     while (1)
// 	{
// 		if (x == end->x && y == end->y && z == end->z)
// 			break ;
// 		if (z != end->z)
// 			z > end->z ? z-- : z++;
// 		if (x != end->x)
// 			x > end->x ? x-- : x++;
// 		if (y != end->y)
// 			y > end->y ? y-- : y++;
// 		cartesian(img, hooks, x, y, z, color);
// 		// printf("updated (%d, %d, %d)\n", x, y, z);
// 	}
// }
