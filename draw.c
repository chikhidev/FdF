/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:16:05 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/15 01:10:16 by abchikhi         ###   ########.fr       */
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

void interpolate_color(t_point *start, t_point *end, int *result_color, double t)
{
    result_color[0] = (int)((1.0 - t) * start->color + t * end->color);
    result_color[1] = (int)((1.0 - t) * (start->color >> 8) + t * (end->color >> 8));
    result_color[2] = (int)((1.0 - t) * (start->color >> 16) + t * (end->color >> 16));
}

// void draw_line(t_hooks *hooks, t_point *point0, t_point *point1)
// {
//     int dx = abs(point1->x - point0->x);
//     int dy = abs(point1->y - point0->y);
//     int sx = point0->x < point1->x ? 1 : -1;
//     int sy = point0->y < point1->y ? 1 : -1;
//     int err = (dx > dy ? dx : -dy) / 2;
//     int e2;

//     double length = sqrt((double)(dx * dx + dy * dy));
//     double t = 0.0; // Interpolation parameter

//     while (1)
//     {
//         int interpolated_color[3];
//         interpolate_color(point0, point1, interpolated_color, t);

//         put_the_pixel(&hooks->img, point0->x, point0->y,
//                       (interpolated_color[2] << 16) | (interpolated_color[1] << 8) | interpolated_color[0]);

//         if (point0->x == point1->x && point0->y == point1->y)
//             break;

//         e2 = err;
//         if (e2 > -dx)
//         {
//             err -= dy;
//             point0->x += sx;
//         }
//         if (e2 < dy)
//         {
//             err += dx;
//             point0->y += sy;
//         }

//         // Update the interpolation parameter
//         t = sqrt((double)((point0->x - point1->x) * (point0->x - point1->x) +
//                           (point0->y - point1->y) * (point0->y - point1->y))) / length;
//     }
// }


void draw_line(t_hooks *hooks, t_point *point0, t_point *point1)
{
    int dx = abs(point1->x - point0->x);
    int dy = abs(point1->y - point0->y);
    int sx = point0->x < point1->x ? 1 : -1;
    int sy = point0->y < point1->y ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;
    int inc[2];
    double length = sqrt((double)(dx * dx + dy * dy));
    double t = 0.0;

    inc[0] = point0->x;
    inc[1] = point0->y;
    while (1)
    {
        int interpolated_color[3];
        interpolate_color(point0, point1, interpolated_color, t);
        put_the_pixel(&hooks->img, inc[0], inc[1],
                      (interpolated_color[2] << 16) | (interpolated_color[1] << 8) | interpolated_color[0]);
        if (inc[0] == point1->x && inc[1] == point1->y)
            break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            inc[0] += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            inc[1] += sy;
        }
        t = sqrt((double)((inc[0] - point1->x) * (inc[0] - point1->x) +
                           (inc[1] - point1->y) * (inc[1] - point1->y))) / length;
    }
}

void link_point(t_hooks *hooks, int row, int col)
{
    t_point strt;
    t_point end;
    
    strt.x = col * hooks->x_factor;
    strt.y = row * hooks->y_factor;
    strt.z = get_z(hooks->matrix[row][col], hooks);
    strt.color = get_color(hooks->matrix[row][col], hooks);
    get_real_point(hooks, &strt);
    if (((col + 1) < hooks->width_grid) && row < hooks->height_grid)
    {
        end.x = (col + 1) * hooks->x_factor;
        end.y = row * hooks->y_factor;
        end.z = get_z(hooks->matrix[row][col + 1], hooks);
        end.color = get_color(hooks->matrix[row][col + 1], hooks);
        get_real_point(hooks, &end);
        draw_line(hooks, &strt, &end);
    }
    if (((row + 1) < hooks->height_grid) && col < hooks->width_grid)
    {
        end.x = col * hooks->x_factor;
        end.y = (row + 1) * hooks->y_factor;
        end.z = get_z(hooks->matrix[row + 1][col], hooks);
        end.color = get_color(hooks->matrix[row + 1][col], hooks);
        get_real_point(hooks, &end);
        draw_line(hooks, &strt, &end);
    }
}
