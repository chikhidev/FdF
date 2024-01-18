#include "./events.h"

void    zoom_in_pos(t_hooks *hooks, int x, int y)
{
    hooks->x_offset -= (x - hooks->x_offset) * hooks->scale;
    hooks->y_offset -= (y - hooks->y_offset) * hooks->scale;
    hooks->scale += .2;
}

void    handle_moving(t_hooks *hooks, int keycode)
{
    if (keycode == 124)
        hooks->x_offset -= hooks->move_step;
    else if (keycode == 123)
        hooks->x_offset += hooks->move_step;
    else if (keycode == 126)
        hooks->y_offset += hooks->move_step;
    else if (keycode == 125)
        hooks->y_offset -= hooks->move_step;
    else
        return ;
    render_next_frame(hooks);
}

void    handle_scaling(t_hooks *hooks, int keycode)
{
    if (keycode == 6)
        (int)hooks->scale < 10 ? hooks->scale += .2 : 0;
    else if (keycode == 7)
        (int)hooks->scale > 0 ? hooks->scale -= .2 : 0;
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
    else if (keycode == 8)
        center_map(hooks);
    else
        return ;
    render_next_frame(hooks);
}
