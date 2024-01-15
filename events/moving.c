#include "./events.h"

void    handle_moving(t_hooks *hooks, int keycode)
{
    if (keycode == 123)
        hooks->x_offset -= 20;
    else if (keycode == 124)
        hooks->x_offset += 20;
    else if (keycode == 125)
        hooks->y_offset += 20;
    else if (keycode == 126)
        hooks->y_offset -= 20;
    else
        return ;
    render_next_frame(hooks);
}

void    handle_scaling(t_hooks *hooks, int keycode)
{
    if (keycode == 6)
        hooks->scale += .2;
    else if (keycode == 7)
        hooks->scale -= .2;
    else
        return ;
    render_next_frame(hooks);
}

void    handle_z_scaling(t_hooks *hooks, int keycode)
{
    if (keycode == 38)
        hooks->z_factor += .5;
    else if (keycode == 40)
        hooks->z_factor -= .5;
    else
        return ;
    render_next_frame(hooks);
}

void    handle_xy_scaling(t_hooks *hooks, int keycode)
{
    if (keycode == 32)
        hooks->x_factor += .5;
    else if (keycode == 34)
        hooks->x_factor -= .5;
    else if (keycode == 43)
        hooks->y_factor += .5;
    else if (keycode == 47)
        hooks->y_factor -= .5;
    else
        return ;
    render_next_frame(hooks);
}