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
                (Y_OFFSET - (hooks->grid.height_grid));
    put_the_pixel(img, real_x, real_y, color);
}

void    draw_cartesian(t_data *img, t_hooks *hooks)
{
    int i;

    i = 0;
	while (i < (WIDTH - hooks->grid.width_grid))
		cartesian(img, hooks, i++, 0, 0, BLUE_COLOR);
	i = 0;
	while (i < (WIDTH - hooks->grid.height_grid))
		cartesian(img, hooks, 0, i++, 0, GREEN_COLOR);
	i = 0;
	while (i < (HEIGHT - hooks->grid.height_grid))
		cartesian(img, hooks, 0, 0, i++, RED_COLOR);
}