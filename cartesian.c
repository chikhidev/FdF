#include "./includes/header.h"

int get_real_x(t_hooks *hooks, int x, int y, int z)
{
    return (hooks->scale * ((hooks->base_cartis[0] * x) +
                (hooks->base_cartis[2] * y) +
                (hooks->base_cartis[4] * z) + hooks->x_offset +
                X_OFFSET));
}

int get_real_y(t_hooks *hooks, int x, int y, int z)
{
    double  height_offset;

    height_offset = (hooks->scale * hooks->z_factor)
        * (hooks->width_grid / cos(hooks->base_cartis[3]));

    return (hooks->scale * ((hooks->base_cartis[1] * x) +
                (hooks->base_cartis[3] * y) +
                (hooks->base_cartis[5] * z) + hooks->y_offset +
                + Y_OFFSET - (height_offset / 2)));
}

void    cartesian(t_hooks *hooks, int x, int y, int z, int color)
{
    int     real_x;
    int     real_y;
    double  height_offset;
    double  width_offset;

    height_offset = (hooks->scale * hooks->z_factor)
        * (hooks->width_grid / cos(hooks->base_cartis[3]));

    width_offset = (hooks->base_cartis[1] * (hooks->width_grid / 2));

    real_x = get_real_x(hooks, x, y, z);
    real_y = get_real_y(hooks, x, y, z);
    put_the_pixel(&hooks->img, real_x, real_y, color);
}

void    draw_cartesian(t_hooks *hooks)
{
    int i;

    printf("inside draw cartesian\n");
    i = 0;
	while (i < (WIDTH - hooks->width_grid))
    {
        printf("here\n");
		cartesian(hooks, i++, 0, 0, BLUE_COLOR);
    }
	i = 0;
	while (i < (WIDTH - hooks->height_grid))
		cartesian(hooks, 0, i++, 0, GREEN_COLOR);
	i = 0;
	while (i < (HEIGHT - hooks->height_grid))
		cartesian(hooks, 0, 0, i++, RED_COLOR);
}

