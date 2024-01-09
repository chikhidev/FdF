/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:16:05 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/09 02:04:23 by abchikhi         ###   ########.fr       */
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

void link_point(t_data *img, t_hooks *hooks, int row, int col)
{
    t_point start;
    t_point end;
    
    start.x = col * ( WIDTH / hooks->grid.width_grid / 2);
    start.y = row * ( WIDTH / hooks->grid.height_grid / 2);
    start.z = get_z(hooks->matrix[row][col]);
    end.x = (col + 1) * ( WIDTH / hooks->grid.width_grid / 2);
    end.y = row * ( WIDTH / hooks->grid.height_grid / 2);
    end.z = get_z(hooks->matrix[row][col + 1]);
    draw_line(img, hooks,
        &start, &end, get_color(hooks->matrix[row][col])
    );

    end.x = col * ( WIDTH / hooks->grid.width_grid / 2);
    end.y = (row + 1) * ( WIDTH / hooks->grid.height_grid / 2);
    end.z = get_z(hooks->matrix[row + 1][col]);
    draw_line(img, hooks,
        &start, &end, get_color(hooks->matrix[row][col])
    );
}
