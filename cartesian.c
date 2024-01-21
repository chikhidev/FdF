#include "./includes/header.h"

//x = (x - y)cos(angle);
//y = (x + y)sin(angle) - z;

//rotation of point (x,y,z) around z axis by angle
// real_x = x * cos(hooks->z_angle) – y * sin(hooks->z_angle)
// real_y = x * sin(hooks->z_angle) + y * cos(hooks->z_angle)

// x = (point->x - hooks->center_point.x) * cos(to_rad(hooks->z_angle)) - 
//         (point->y - hooks->center_point.y) * sin(to_rad(hooks->z_angle));

// y = (point->x - hooks->center_point.x) * sin(to_rad(hooks->z_angle)) + 
//         (point->y - hooks->center_point.y) * cos(to_rad(hooks->z_angle));

double to_rad(double angle)
{
    return (angle * (M_PI / 180));
}

void    extract(t_hooks *hooks, t_point *point)
{
    t_point temp;
    double ay;
    double az;

    ay = to_rad(hooks->y_angle);
    az = to_rad(hooks->z_angle);
    temp.x = (point->x - hooks->center_point.x) * cos(az) -
        (point->y - hooks->center_point.y) * sin(az) +
        hooks->center_point.x;

    temp.y = (point->x - hooks->center_point.x) * sin(az) +
        (point->y - hooks->center_point.y) * cos(az) +
        hooks->center_point.y;
    point->x = temp.x;
    point->y = temp.y;
}

inline void    get_real_point(t_hooks *hooks, t_point *point)
{
    t_point real_point;

    extract(hooks, point);
    real_point.x = hooks->scale * ((point->x - point->y) * cos(to_rad(hooks->facing_angle))) + hooks->x_offset;
    real_point.y = hooks->scale * ((point->x + point->y) * sin(to_rad(hooks->facing_angle)) - point->z) + hooks->y_offset;
    point->x = real_point.x;
    point->y = real_point.y;
}

inline void    cartesian(t_hooks *hooks, t_point *point)
{
    int     real_x;
    int     real_y;

    extract(hooks, point);
    real_x = hooks->scale * ((point->x - point->y) * cos(to_rad(hooks->facing_angle))) + hooks->x_offset;
    real_y = hooks->scale * ((point->x + point->y) * sin(to_rad(hooks->facing_angle)) - point->z) + hooks->y_offset;
    put_the_pixel(&hooks->img, real_x, real_y, point->color);
}
