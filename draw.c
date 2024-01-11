/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:16:05 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/11 22:00:11 by abchikhi         ###   ########.fr       */
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

void    draw_line(t_hooks *hooks, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1)
    {
        put_the_pixel(&hooks->img, x0, y0, 0x00FFFFFF);
        if (x0 == x1 && y0 == y1)
            break ;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void link_point(t_hooks *hooks, int row, int col)
{
    t_point strt;
    t_point end;
    
    strt.x = col * ( WIDTH / hooks->width_grid / 2);
    strt.y = row * ( WIDTH / hooks->height_grid / 2);
    strt.z = get_z(hooks->matrix[row][col], hooks);
    
    if (((col + 1) < hooks->width_grid) && row < hooks->height_grid)
    {
        end.x = (col + 1) * ( WIDTH / hooks->width_grid / 2);
        end.y = row * ( WIDTH / hooks->height_grid / 2);
        end.z = get_z(hooks->matrix[row][col + 1], hooks);
        draw_line(hooks,
            get_real_x(hooks, strt.x, strt.y, strt.z),
            get_real_y(hooks, strt.x, strt.y, strt.z),
            get_real_x(hooks, end.x, end.y, end.z),
            get_real_y(hooks, end.x, end.y, end.z)
        );
    }
    if (((row + 1) < hooks->height_grid) && col < hooks->width_grid)
    {
        end.x = col * ( WIDTH / hooks->width_grid / 2);
        end.y = (row + 1) * ( WIDTH / hooks->height_grid / 2);
        end.z = get_z(hooks->matrix[row + 1][col], hooks);
        draw_line(hooks,
            get_real_x(hooks, strt.x, strt.y, strt.z),
            get_real_y(hooks, strt.x, strt.y, strt.z),
            get_real_x(hooks, end.x, end.y, end.z),
            get_real_y(hooks, end.x, end.y, end.z)
        );
    }
}
