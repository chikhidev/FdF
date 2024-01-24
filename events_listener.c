#include "./includes/header.h"
#include "./events/events.h"

void    show_input_label(t_hooks *hooks, int keycode, int allow)
{
    char   *tmp;
    char    *added;

    if (allow)
    {
        added = get_char(keycode);
        tmp = ft_strjoin(hooks->cmd, added);
        free(added);
        free(hooks->cmd);
        hooks->cmd = tmp;
    }
    render_next_frame(hooks);
    mlx_string_put(hooks->mlx, hooks->win, 20, HEIGHT - 40, 
                ft_strlen (hooks->cmd) > 20 ? RED_COLOR : GREEN_COLOR, ">");
    mlx_string_put(hooks->mlx, hooks->win, 40, HEIGHT - 40, WHITE_COLOR, hooks->cmd);
}

int command_line_handler(t_hooks *hooks, int keycode)
{
    char    *tmp;

    if (!hooks->cmd_mode || (ft_strlen(hooks->cmd) > 20 && keycode != 51))
        return (1);
    if (keycode == 53)
    {
        free(hooks->cmd);
        hooks->cmd = ft_strdup("");
        hooks->cmd_mode = 0;
        render_next_frame(hooks);
        return (0);
    }
    if (keycode == 51)
    {
        tmp = ft_substr(hooks->cmd, 0, ft_strlen(hooks->cmd) - 1);
        free(hooks->cmd);
        hooks->cmd = tmp;
        show_input_label(hooks, keycode, 0);
        return (0);
    }
    show_input_label(hooks, keycode, 1);
   if (hooks->cmd_mode && keycode == 36)
    {
        execute_cmd(hooks);
        free(hooks->cmd);
        hooks->cmd = ft_strdup("");
        render_next_frame(hooks);
        show_input_label(hooks, keycode, 0);
        return (0);
    }
    return (0);
}

int	event_listener(int keycode, t_hooks *hooks)
{
    if (keycode == 17 && !hooks->cmd_mode && WIDTH > 500)
    {
        hooks->cmd_mode = !hooks->cmd_mode;
        show_input_label(hooks, keycode, 0);
        return (0);
    }
    if (command_line_handler(hooks, keycode) == 0)
        return (0);
    reset_exit_handler(hooks, keycode);
    link_cart_handler(hooks, keycode);
    handle_scaling(hooks, keycode);
    handle_moving(hooks, keycode);
    handle_z_scaling(hooks, keycode);
    handle_xy_scaling(hooks, keycode);
    view_handle(hooks, keycode);
	return (0);
}
