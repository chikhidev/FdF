#include "./events.h"

void rotate_x(t_hooks *hooks, double angle)
{
    if (angle > 360 || angle < -360)
    {
        angle = 0;
        hooks->x_angle = 0;
    }
    angle = angle * M_PI / 180;

    double temp1 = hooks->base_cartis[1];
    double temp2 = hooks->base_cartis[2];

    hooks->base_cartis[1] = temp1 * cos(angle) + temp2 * sin(angle);
    hooks->base_cartis[2] = -temp1 * sin(angle) + temp2 * cos(angle);
}

void rotate_y(t_hooks *hooks, double angle)
{
    if (angle > 360 || angle < -360)
    {
        angle = 0;
        hooks->y_angle = 0;
    }
    angle = angle * M_PI / 180;

    double temp0 = hooks->base_cartis[0];
    double temp1 = hooks->base_cartis[1];
    double temp2 = hooks->base_cartis[2];
    double temp3 = hooks->base_cartis[3];
    double temp4 = hooks->base_cartis[4];
    double temp5 = hooks->base_cartis[5];

    hooks->base_cartis[0] = temp0 * cos(angle) + temp2 * sin(angle);
    hooks->base_cartis[1] = temp1;
    hooks->base_cartis[2] = -temp0 * sin(angle) + temp2 * cos(angle);
    hooks->base_cartis[3] = temp3 * cos(angle) + temp5 * sin(angle);
    hooks->base_cartis[4] = temp4;
    hooks->base_cartis[5] = -temp3 * sin(angle) + temp5 * cos(angle);
}