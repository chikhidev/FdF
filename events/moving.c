#include "./events.h"

void    handle_moving(t_hooks *hooks, int keycode)
{
    if (keycode == 123)
        hooks->x_offset -= 10;
    else if (keycode == 124)
        hooks->x_offset += 10;
    else if (keycode == 125)
        hooks->y_offset += 10;
    else if (keycode == 126)
        hooks->y_offset -= 10;
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