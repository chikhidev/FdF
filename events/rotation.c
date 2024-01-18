#include "./events.h"

//x' = x * cos(a) - y * sin(a)
//y' = x * sin(a) + y * cos(a)

void    rotate_y(t_hooks *hooks, double angle)
{
    double  cos_angle;
    double  sin_angle;
    double  tmp_x;
    double  tmp_z;

    cos_angle = cos(angle);
    sin_angle = sin(angle);
    tmp_x = hooks->base_cartis[0];
    tmp_z = hooks->base_cartis[4];
    hooks->base_cartis[0] = tmp_x * cos_angle - tmp_z * sin_angle;
    hooks->base_cartis[4] = tmp_x * sin_angle + tmp_z * cos_angle;
    tmp_x = hooks->base_cartis[2];
    tmp_z = hooks->base_cartis[5];
    hooks->base_cartis[2] = tmp_x * cos_angle - tmp_z * sin_angle;
    hooks->base_cartis[5] = tmp_x * sin_angle + tmp_z * cos_angle;
}

void    view_handle(t_hooks *hooks, int keycode)
{
    if (keycode == 3)
    {
        if (hooks->base_cartis[0] == 1 && hooks->base_cartis[1] == 0)
            iso_view(hooks);
        else
            flat_view(hooks);
    }
    else if (keycode == 2)
        rotate_y(hooks, .5);
    else
        return;
    render_next_frame(hooks);
}