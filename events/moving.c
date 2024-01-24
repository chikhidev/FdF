#include "./events.h"

void    handle_moving(t_hooks *hooks, int keycode)
{
    if (keycode == 124)
        update_limit(&hooks->x_offset, 5000, hooks->move_step);
    else if (keycode == 123)
        update_limit(&hooks->x_offset, -5000, -hooks->move_step);
    else if (keycode == 126)
        update_limit(&hooks->y_offset, 5000, hooks->move_step);
    else if (keycode == 125)
        update_limit(&hooks->y_offset, -5000, -hooks->move_step);
    else
        return ;
    render_next_frame(hooks);
}

void    handle_scaling(t_hooks *hooks, int keycode)
{
    if (keycode == 6)
        update_limit(&hooks->scale, 10, .2);
    else if (keycode == 7)
        update_limit(&hooks->scale, 0, -.2);
    else
        return ;
    render_next_frame(hooks);
}

void    handle_z_scaling(t_hooks *hooks, int keycode)
{
    if (keycode == 38)
        update_limit(&hooks->z_factor, 200, .5);
    else if (keycode == 40)
        update_limit(&hooks->z_factor, -200, -.5);
    else
        return ;
    render_next_frame(hooks);
}

void    handle_xy_scaling(t_hooks *hooks, int keycode)
{
    if (keycode == 32)
        update_limit(&hooks->x_factor, 200, .5);
    else if (keycode == 34)
        update_limit(&hooks->x_factor, 0, -.5);
    else if (keycode == 43)
        update_limit(&hooks->y_factor, 200, .5);
    else if (keycode == 47)
        update_limit(&hooks->y_factor, 0, -.5);
    else
        return ;
    render_next_frame(hooks);
}
