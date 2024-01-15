#include "./events.h"

void reset_exit_handler(t_hooks *hooks, int keycode)
{
    if (keycode == 53)
    {
        ft_printf("Bye\n");
        exit_free(hooks);
    }
    else if (keycode == 15)
    {
        config_hooks(hooks);
        hooks->z_factor = 50;
        if (hooks->z_max > Z_MOY || hooks->z_min < -Z_MOY)
            hooks->z_factor = 1;
        render_next_frame(hooks);
    }
}

void    link_cart_handler(t_hooks *hooks, int keycode)
{
    if (keycode == 37)
        hooks->allow_link = !hooks->allow_link;
    else if (keycode == 8)
        hooks->show_cartesian = !hooks->show_cartesian;
    else
        return ;
    render_next_frame(hooks);
}