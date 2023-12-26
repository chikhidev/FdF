#include "./includes/header.h"

void    cartesian(t_data *img, int x, int y, int color)
{
    x = WIDTH / 2 + x - (AXIS_LENGTH / 3);
    y = HEIGHT / 2 + y - (AXIS_LENGTH / 3);
    put_the_pixel(img, x, y, color);
}

void    draw_in_x(t_data *img, int x, int y, int color)
{
    cartesian(img, x, y, color);
}

void draw_cartesian_axis(t_data *img)
{
    int i;

    i = 0;
    while (i < AXIS_LENGTH)
    {
        cartesian(img, i, 0, 0xFF0000);
        i++;
    }

    i = 0;
    while (i < AXIS_LENGTH)
    {
        cartesian(img, 0, i, 0x00FF00);
        i++;
    }

    i = 0;
    double angle = 90 * M_PI / 180;
    printf(GREEN "angle: %f\n", angle);
    while (i < AXIS_LENGTH)
    {
        int x = i * cos(angle);
        int y = i * sin(angle);
        cartesian(img, x, y, 0x0000FF);
        i++;
    }
}
