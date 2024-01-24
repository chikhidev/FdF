#include "./events.h"

void    reset(t_hooks *hooks)
{
    free(hooks->cmd);
    hooks->cmd = ft_strdup("");
    config_hooks(hooks);
    center_map(hooks);
    hooks->z_factor = 5;
    if (hooks->z_max > Z_MOY || hooks->z_min < -Z_MOY)
        hooks->z_factor = 1;
}

void reset_exit_handler(t_hooks *hooks, int keycode)
{
    if (keycode == 53 && !hooks->cmd_mode)
    {
        ft_printf("Bye\n");
        exit_free(hooks);
    }
    else if (keycode == 53 && hooks->cmd_mode)
    {
        free(hooks->cmd);
        hooks->cmd = ft_strdup("");
        hooks->cmd_mode = 0;
    }
    else if (keycode == 15)
    {
        reset(hooks);
        render_next_frame(hooks);
    }
}

void    link_cart_handler(t_hooks *hooks, int keycode)
{
    if (keycode == 37)
        hooks->allow_link = !hooks->allow_link;
    else
        return ;
    render_next_frame(hooks);
}
