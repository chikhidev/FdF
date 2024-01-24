#include "./events.h"

void    update_limit(double   *ptr, double limit, double value)
{
    if (limit > 0)
    {
        if (*ptr < limit)
            *ptr += value;
    }
    else
    {
        if (*ptr > limit)
            *ptr += value;
    }
}

void    execute_cmd(t_hooks *hooks)
{
    int len;

    if (!hooks->cmd_mode)
        return ;
    len = (int)ft_strlen(hooks->cmd);
    ft_printf("len = %d\n", len);
    if (ft_strncmp(hooks->cmd, "exit", 4) == 0 && len == 4)
        exit_free(hooks);
    else if (ft_strncmp(hooks->cmd, "parallel", 8) == 0 && len == 8)
        hooks->parallel_view = 1;
    else if (ft_strncmp(hooks->cmd, "isometric", 9) == 0 && len == 9)
        hooks->parallel_view = 0;
    else if (ft_strncmp(hooks->cmd, "left", 4) == 0 && len == 4)
        update_limit(&hooks->x_offset, -5000, -hooks->move_step);
    else if (ft_strncmp(hooks->cmd, "right", 5) == 0 && len == 5)
        update_limit(&hooks->x_offset, 5000, hooks->move_step);
    else if (ft_strncmp(hooks->cmd, "up", 2) == 0 && len == 2)
        update_limit(&hooks->y_offset, -5000, -hooks->move_step);
    else if (ft_strncmp(hooks->cmd, "down", 4) == 0 && len == 4)
        update_limit(&hooks->y_offset, 5000, hooks->move_step);
    else if (ft_strncmp(hooks->cmd, "zoomin", 6) == 0 && len == 6)
        update_limit(&hooks->scale, 10, .2);
    else if (ft_strncmp(hooks->cmd, "zoomout", 7) == 0 && len == 7)
        update_limit(&hooks->scale, .3, -.2);
    else if (ft_strncmp(hooks->cmd, "zinc", 4) == 0 && len == 4)
        update_limit(&hooks->z_factor, 200, .5);
    else if (ft_strncmp(hooks->cmd, "zdec", 4) == 0 && len == 4)
        update_limit(&hooks->z_factor, -200, -.5);
    else if (ft_strncmp(hooks->cmd, "xinc", 4) == 0 && len == 4)
        update_limit(&hooks->x_factor, 200, .5);
    else if (ft_strncmp(hooks->cmd, "xdec", 4) == 0 && len == 4)
        update_limit(&hooks->x_factor, 0, -.5);
    else if (ft_strncmp(hooks->cmd, "yinc", 4) == 0 && len == 4)
        update_limit(&hooks->y_factor, 200, .5);
    else if (ft_strncmp(hooks->cmd, "ydec", 4) == 0 && len == 4)
        update_limit(&hooks->y_factor, 0, -.5);
    else if (ft_strncmp(hooks->cmd, "rotate", 6) == 0 && len == 6)
        animate_angle_update(&hooks->z_angle, 2);
    else if (ft_strncmp(hooks->cmd, "derotate", 8) == 0 && len == 8)
        animate_angle_update(&hooks->z_angle, -2);
    else if (ft_strncmp(hooks->cmd, "link", 4) == 0 && len == 4)
        hooks->allow_link = 1;
    else if (ft_strncmp(hooks->cmd, "unlink", 6) == 0 && len == 6)
        hooks->allow_link = 0;
    else
        ft_printf("command not found\n");
}
