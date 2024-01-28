/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:16:05 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/28 01:24:52 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

int	get_color(char *str, t_hooks *hooks)
{
	char	*color;
	int		color_value;
	int		z;

	color = ft_strchr(str, ',');
	if (color)
	{
		color_value = atoi_base(color + 1, 16);
		return (color_value);
	}
	z = get_z(str, hooks);
	if (z < -10)
		return (LOW_LEVEL_COLOR);
	else if (z >= -10 && z <= 10)
		return (WHITE_COLOR);
	else
		return (HIGH_LEVEL_COLOR);
}

void	put_the_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	choose_color(t_point *p0, t_point *p1)
{
	if (p1->z > p0->z && p1->z > 0)
		return (p1->color);
	else if (p0->z > p1->z && p0->z > 0)
		return (p0->color);
	else if (p1->z < p0->z && p1->z < 0)
		return (p1->color);
	else if (p0->z < p1->z && p0->z < 0)
		return (p0->color);
	return (p0->color);
}

void	dda(t_hooks *hooks, t_point *point0, t_point *point1)
{
	int			dx;
	int			dy;
	t_drawer	drawer;

	dx = point1->x - point0->x;
	dy = point1->y - point0->y;
	if (abs(dx) > abs(dy))
		drawer.steps = abs(dx);
	else
		drawer.steps = abs(dy);
	drawer.x_inc = dx / (double)drawer.steps;
	drawer.y_inc = dy / (double)drawer.steps;
	drawer.x = point0->x;
	drawer.y = point0->y;
	drawer.i = 0;
	while (drawer.i <= drawer.steps)
	{
		put_the_pixel(&hooks->img, drawer.x, drawer.y, choose_color(point0,
				point1));
		drawer.x += drawer.x_inc;
		drawer.y += drawer.y_inc;
		drawer.i++;
	}
}

void	link_point(t_hooks *hooks, int row, int col)
{
	t_point	strt;
	t_point	end;

	init_point(hooks, &strt, row, col);
	get_real_point(hooks, &strt);
	if ((strt.x < 0 || strt.x >= WIDTH) && (strt.y < 0 || strt.y >= HEIGHT))
		return ;
	if ((col + 1) < hooks->width_grid)
	{
		init_point(hooks, &end, row, col + 1);
		get_real_point(hooks, &end);
		dda(hooks, &strt, &end);
	}
	if ((row + 1) < hooks->height_grid)
	{
		init_point(hooks, &end, row + 1, col);
		get_real_point(hooks, &end);
		dda(hooks, &strt, &end);
	}
}
