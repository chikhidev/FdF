/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:16:05 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/20 21:40:44 by abchikhi         ###   ########.fr       */
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

int choose_color(t_point *p0, t_point *p1)
{
    if (p0->color == p1->color)
        return (p0->color);
    if (p1->z > p0->z)
        return (p1->color);
    else if (p0->z > p1->z)
        return (p0->color);
    return (WHITE_COLOR);
}

void init_point(t_hooks *hooks, t_point *point, int row, int col)
{
    point->x = col * hooks->x_factor;
    point->y = row * hooks->y_factor;
    point->z = get_z(hooks->matrix[row][col], hooks);
    point->color = get_color(hooks->matrix[row][col], hooks);
    get_real_point(hooks, point);
}

void dda(t_hooks *hooks, t_point *point0, t_point *point1)
{
    int dx = point1->x - point0->x;
    int dy = point1->y - point0->y;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    double x_inc = dx / (double)steps;
    double y_inc = dy / (double)steps;
    double x = point0->x;
    double y = point0->y;
    int     i = 0;

    while (i <= steps)
    {
        put_the_pixel(&hooks->img, x, y, choose_color(point0, point1));
        x += x_inc;
        y += y_inc;
        i++;
    }
}

void link_point(t_hooks *hooks, int row, int col)
{
    t_point strt, end;

    init_point(hooks, &strt, row, col);
    if (strt.x < 0 || strt.x >= WIDTH || strt.y < 0 || strt.y >= HEIGHT)
        return;
    if ((col + 1) < hooks->width_grid)
    {
        init_point(hooks, &end, row, col + 1);
        dda(hooks, &strt, &end);
    }
    if ((row + 1) < hooks->height_grid)
    {
        init_point(hooks, &end, row + 1, col);
        dda(hooks, &strt, &end);
    }
}
