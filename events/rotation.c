#include "./events.h"
#include <time.h>

//x' = x * cos(a) - y * sin(a)
//y' = x * sin(a) + y * cos(a)

void    intro_animation(t_hooks *hooks)
{
    while (hooks->scale < 1)
    {
        hooks->scale += 0.01;
        render_next_frame(hooks);
    }
}

void    view_handle(t_hooks *hooks, int keycode)
{
    if (keycode == 3)
    {
        if (hooks->facing_angle == 0)
        {
            hooks->facing_angle = 30;
            hooks->z_angle = 0;
            hooks->x_angle = 0;
        }
        else
            hooks->facing_angle = 0;
    }
    else if (keycode == 2)
    {
        if ((int)hooks->z_angle < 359)
            hooks->z_angle += 5;
        else
            hooks->z_angle = 0;
    }
    else if (keycode == 0)
    {
        if (hooks->z_angle > 0)
            hooks->z_angle -= 5;
        else
            hooks->z_angle = 360;
    }
    else if (keycode == 13)
        hooks->y_angle += 5;
    else if (keycode == 1)
        hooks->y_angle -= 5;
    else
        return;
    render_next_frame(hooks);
}
