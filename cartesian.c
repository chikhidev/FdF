#include "./includes/header.h"

//x = (x - y)cos(angle);
//y = (x + y)sin(angle) - z;

//rotation of point (x,y,z) around z axis by angle
// real_x = x * cos(hooks->z_angle) – y * sin(hooks->z_angle)
// real_y = x * sin(hooks->z_angle) + y * cos(hooks->z_angle)

double to_rad(double angle) {
    return (angle * (M_PI / 180));
}

int get_real_x(t_hooks *hooks, t_point *point)
{
    int x;
    int y;

    x = (point->x - hooks->center_point.x) * cos(to_rad(hooks->z_angle)) - 
                (point->y - hooks->center_point.y) * sin(to_rad(hooks->z_angle));
    y = (point->x - hooks->center_point.x) * sin(to_rad(hooks->z_angle)) + 
                (point->y - hooks->center_point.y) * cos(to_rad(hooks->z_angle));
    point->x = x;
    point->y = y;
    return (hooks->scale * 
            (
                (point->x - point->y) *
                cos(to_rad(hooks->facing_angle)
                )
            ) + 
            hooks->x_offset);
}

int get_real_y(t_hooks *hooks, t_point *point)
{
    int x;
    int y;


    x = (point->x - hooks->center_point.x) * cos(to_rad(hooks->z_angle)) - 
                (point->y - hooks->center_point.y) * sin(to_rad(hooks->z_angle));
    y = (point->x - hooks->center_point.x) * sin(to_rad(hooks->z_angle)) +
                (point->y - hooks->center_point.y) * cos(to_rad(hooks->z_angle));
    point->x = x;
    point->y = y;
    return (hooks->scale * (
                (point->x + point->y) * 
                sin(to_rad(hooks->facing_angle)) - point->z) + 
                hooks->y_offset);
}

void    get_real_point(t_hooks *hooks, t_point *point)
{
    t_point real_point;

    real_point.x = get_real_x(hooks, point);
    real_point.y = get_real_y(hooks, point);
    point->x = real_point.x;
    point->y = real_point.y;
}

void    cartesian(t_hooks *hooks, t_point *point)
{
    int     real_x;
    int     real_y;

    real_x = get_real_x(hooks, point);
    real_y = get_real_y(hooks, point);
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