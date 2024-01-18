#include "./events.h"

//x' = x * cos(a) - y * sin(a)
//y' = x * sin(a) + y * cos(a)

void    rotate_x(t_hooks *hooks, double angle)
{
    double  cos_angle;
    double  sin_angle;
    double  temp;

    angle = angle * M_PI / 180;
    cos_angle = cos(angle);
    sin_angle = sin(angle);
    temp = hooks->base_cartis[1];
    hooks->base_cartis[1] = hooks->base_cartis[1] * cos_angle - hooks->base_cartis[2] * sin_angle;
    hooks->base_cartis[2] = temp * sin_angle + hooks->base_cartis[2] * cos_angle;
    temp = hooks->base_cartis[3];
    hooks->base_cartis[3] = hooks->base_cartis[3] * cos_angle - hooks->base_cartis[4] * sin_angle;
    hooks->base_cartis[4] = temp * sin_angle + hooks->base_cartis[4] * cos_angle;
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
    else if (keycode == 5)
    {
        if (hooks->move_step == 1)
            reset(hooks);
        else
        {
            setup_game(hooks);
            hooks->move_step = 1;
            hooks->x_offset = 0;
            hooks->y_offset = 0;
            hooks->scale = 10;
        }
    }
    else if (keycode == 2)
        rotate_x(hooks, 5);
    else
        return;
    render_next_frame(hooks);
}