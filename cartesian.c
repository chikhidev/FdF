#include "./includes/header.h"

void    cartesian(t_data *img, t_hooks *hooks, int x, int y, int z, int color)
{
    int real_x, real_y;

    real_x = (hooks->base_cartis[0] * x) +
                (hooks->base_cartis[2] * y) +
                (hooks->base_cartis[4] * z) +
                X_OFFSET;
    real_y = (hooks->base_cartis[1] * x) +
                (hooks->base_cartis[3] * y) +
                (hooks->base_cartis[5] * z) +
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