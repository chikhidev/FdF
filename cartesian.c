#include "./includes/header.h"

int get_real_x(t_hooks *hooks, int x, int y, int z)
{
    return (hooks->scale * (
                (hooks->base_cartis[0] * x) +
                (hooks->base_cartis[2] * y) +
                (hooks->base_cartis[4] * z) + hooks->x_offset
            ));
}

int get_real_y(t_hooks *hooks, int x, int y, int z)
{
    return (hooks->scale * (
                (hooks->base_cartis[1] * x) +
                (hooks->base_cartis[3] * y) +
                (hooks->base_cartis[5] * z) + hooks->y_offset
            ));
}

void    get_real_point(t_hooks *hooks, t_point *point)
{
    t_point real_point;

    real_point.x = get_real_x(hooks, point->x, point->y, point->z);
    real_point.y = get_real_y(hooks, point->x, point->y, point->z);
    point->x = real_point.x;
    point->y = real_point.y;
}

void    cartesian(t_hooks *hooks, t_point *point)
{
    int     real_x;
    int     real_y;

    real_x = get_real_x(hooks, point->x, point->y, point->z);
    real_y = get_real_y(hooks, point->x, point->y, point->z);
    put_the_pixel(&hooks->img, real_x, real_y, point->color);
}

/*
(1,0,0) → (a,b) (0,1,0) → (c,d) (0,0,1) → (e,f)

Generalized Formula
The generalized formula for the transformation is:

(x,y,z)→ (a⋅x + c⋅y + e⋅z, b⋅x + d⋅y + f⋅z)
*/

// void    read_data_from_display(t_hooks *hooks, int x, int y)
// {

// }