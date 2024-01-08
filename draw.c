/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:16:05 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/08 03:33:59 by abchikhi         ###   ########.fr       */
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

void draw_line(t_data *img, t_hooks *hooks, int x1, int y1, int z1, int x2, int y2, int z2, int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int dz = abs(z2 - z1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int sz = (z1 < z2) ? 1 : -1;

    int err1 = (dx > dy && dx > dz) ? dx / 2 : (dy > dx && dy > dz) ? dy / 2 : dz / 2;
    int err2;

    while (1) {
        cartesian(img, hooks, x1, y1, z1, color);

        if (x1 == x2 && y1 == y2 && z1 == z2)
            break;
        err2 = err1;
        if (err2 > -dx) {
            err1 -= dy;
            x1 += sx;
        }
        if (err2 > -dy) {
            err1 -= dz;
            y1 += sy;
        }
        if (err2 < dz) {
            err1 += dx;
            z1 += sz;
        }
    }
}

void link_point(t_data *img, t_hooks *hooks, int row, int col) {
    int x = col * (WIDTH / hooks->grid.width_grid / 2);
    int y = row * (HEIGHT / hooks->grid.height_grid / 2);
    int z1 = get_z(hooks->matrix[row][col]);
    int z2 = get_z(hooks->matrix[row][col + 1]);
    int z3 = get_z(hooks->matrix[row + 1][col]);
    int color = get_color(hooks->matrix[row][col]);

    // Draw the first line
    draw_line(img, hooks, x, y, z1,
        x + (WIDTH / hooks->grid.width_grid / 2), y, z2, color);

    // Draw the second line
    draw_line(img, hooks, x + (WIDTH / hooks->grid.width_grid / 2),
        y, z2, x, y + (HEIGHT / hooks->grid.height_grid / 2),
        z3, color);
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
