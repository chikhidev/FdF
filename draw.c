/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:16:05 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/10 04:56:30 by abchikhi         ###   ########.fr       */
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

//remove ----------------------------------
void draw_line(t_hooks *hooks, t_point *start, t_point *end, int color) {
    int k;
    float x_increment, y_increment, z_increment;
    float x = start->x, y = start->y, z = start->z;

    int dx = end->x - start->x;
    int dy = end->y - start->y;
    int dz = end->z - start->z;

    int max_d = (abs(dx) > abs(dy)) ? ((abs(dx) > abs(dz)) ? abs(dx) : abs(dz)) : ((abs(dy) > abs(dz)) ? abs(dy) : abs(dz));

    x_increment = (float)dx / max_d;
    y_increment = (float)dy / max_d;
    z_increment = (float)dz / max_d;

    cartesian(hooks, round(x), round(y), round(z), color);

    for (k = 0; k < max_d; ++k) {
        x += x_increment;
        y += y_increment;
        z += z_increment;

        cartesian(hooks, round(x), round(y), round(z), color);
    }
}
//remove ---------------------------------- ^^^^^^^^^^^^^^^^^^^

void link_point(t_hooks *hooks, int row, int col)
{
    t_point start;
    t_point end;
    
    if (((col + 1) < hooks->width_grid) && row < hooks->height_grid)
    {
        start.x = col * ( WIDTH / hooks->width_grid / 2);
        start.y = row * ( WIDTH / hooks->height_grid / 2);
        start.z = get_z(hooks->matrix[row][col], hooks);
        end.x = (col + 1) * ( WIDTH / hooks->width_grid / 2);
        end.y = row * ( WIDTH / hooks->height_grid / 2);
        end.z = get_z(hooks->matrix[row][col + 1], hooks);
        draw_line(hooks,
            &start, &end, get_color(hooks->matrix[row][col], hooks)
        );
    }

    if (((row + 1) < hooks->height_grid) && col < hooks->width_grid)
    {
        end.x = col * ( WIDTH / hooks->width_grid / 2);
        end.y = (row + 1) * ( WIDTH / hooks->height_grid / 2);
        end.z = get_z(hooks->matrix[row + 1][col], hooks);
        draw_line(hooks,
            &start, &end, get_color(hooks->matrix[row][col], hooks)
        );
    }
}
