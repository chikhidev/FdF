#include "./includes/header.h"

void    cartesian(t_data *img, t_hooks *hooks, int x, int y, int z, int color)
{
    int real_x, real_y;

    real_x = (hooks->base_cartis->a * x) +
                (hooks->base_cartis->c * y) +
                (hooks->base_cartis->e * z) +
                X_OFFSET;
    real_y = (hooks->base_cartis->b * x) +
                (hooks->base_cartis->d * y) +
                (hooks->base_cartis->f * z) +
                Y_OFFSET;
    // printf("[DEBUG]: a: %d b: %d c: %d d: %d e: %d f: %d\nreal x: %d, real y: %d\n", 
    //         hooks->base_cartis->a,
    //         hooks->base_cartis->b,
    //         hooks->base_cartis->c,
    //         hooks->base_cartis->d,
    //         hooks->base_cartis->e,
    //         hooks->base_cartis->f,
    //         real_x, real_y
    // );
    put_the_pixel(img, real_x, real_y, color);
}

void    draw_cartesian(t_data *img, t_hooks *hooks)
{
    int i;

    i = 0;
	while (i < (WIDTH / 2))
		cartesian(img, hooks, i++, 0, 0, BLUE_COLOR);
	i = 0;
	while (i < (WIDTH / 2))
		cartesian(img, hooks, 0, i++, 0, GREEN_COLOR);
	i = 0;
	while (i < (HEIGHT / 2))
		cartesian(img, hooks, 0, 0, i++, RED_COLOR);
}