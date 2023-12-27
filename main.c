/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:15:08 by abchikhi          #+#    #+#             */
/*   Updated: 2023/12/25 16:02:45 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

void init_view(t_display *display, t_hooks *hooks, t_data *img)
{
	display->mlx = mlx_init();
	display->win = mlx_new_window(display->mlx, WIDTH, HEIGHT, WINDOW_NAME);
	img->img = mlx_new_image(display->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(
							img->img,
							&img->bits_per_pixel,
							&img->line_length,
							&img->endian);
	/*(1,0,0) → (a,b) (0,1,0) → (c,d) (0,0,1) → (e,f)*/
	hooks->base_cartis->a = 1;
	hooks->base_cartis->b = 0;
	hooks->base_cartis->c = -1;
	hooks->base_cartis->d = 1;
	hooks->base_cartis->e = 0;
	hooks->base_cartis->f = -1;
}

void rotate_cube(t_point *cube_points, float angle)
{
    t_point *tmp = cube_points;
    while (tmp)
    {
        int new_x = tmp->x * cos(angle) - tmp->z * sin(angle);
        int new_z = tmp->x * sin(angle) + tmp->z * cos(angle);
        tmp->x = new_x;
        tmp->z = new_z;
        tmp = tmp->next;
    }
}

int update_and_draw(t_display *display, t_data *img, t_hooks *hooks, t_point *points)
{
    static float angle = 0.0;
	t_point *cube_copy = copy_point_list(points);

    img->img = mlx_new_image(display->mlx, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(
                        img->img,
                        &img->bits_per_pixel,
                        &img->line_length,
                        &img->endian);

    // Rotate the cube with a small angle increment
    rotate_cube(cube_copy, angle);
    angle += .0005;

    // Draw the entire scene
    draw_cartesian(img, hooks);
    mark_points(&cube_copy, img, hooks, WHITE_COLOR);

    // Put the new image to the window
    mlx_put_image_to_window(display->mlx, display->win, img->img, 0, 0);

    // Destroy the previous image to avoid memory leaks
    mlx_destroy_image(display->mlx, img->img);

    return 0;
}

int main(int ag, char **av)
{
	t_display	display;
	t_data		img;
	t_hooks		hooks;

	if (ag != 2)
	{
		write(2, "Please use syntax:\n./fdf file.fdf\n", 35);
		return (1);
	}

	init_view(&display, &hooks, &img);

	(void)av;
	// *hooks.error = 0;
	// if (!get_matrix(&hooks, av[1], &hooks.grid))
	// {
	// 	write(2, "Error\n", 6);
	// 	return (1);
	// }

	draw_cartesian(&img, &hooks);
	
	t_point *cube_points = NULL;

	add_point(&cube_points, new_point(0, 0, 0));     // 1
	add_point(&cube_points, new_point(0, 0, 70));    // 2
	add_point(&cube_points, new_point(70, 0, 70));   // 3
	add_point(&cube_points, new_point(0, 70, 0));    // 5
	add_point(&cube_points, new_point(70, 70, 0));   // 8 (Changed order)
	add_point(&cube_points, new_point(70, 0, 0));    // 4 (Changed order)
	add_point(&cube_points, new_point(0, 70, 70));   // 6
	add_point(&cube_points, new_point(70, 70, 70));  // 7

    
	mark_points(&cube_points, &img, &hooks, WHITE_COLOR);
	// mlx_loop_hook(display.mlx, update_and_draw, &img);
	// mlx_put_image_to_window(display.mlx, display.win, img.img, 0, 0);
	
	mlx_put_image_to_window(
							display.mlx,
							display.win,
							img.img,
							0, 0);
	mlx_loop(display.mlx);
	return (0);
}

