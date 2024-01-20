#include "./includes/header.h"
#include "./events/events.h"

void    center_map(t_hooks *hooks)
{
    t_point left;
    t_point right;
    t_point top;
    t_point bottom;

    left.x = 0;
    left.y = hooks->height_grid * hooks->y_factor;
    left.z = get_z(hooks->matrix[hooks->height_grid - 1][0], hooks);
    right.x = hooks->width_grid * hooks->x_factor;
    right.y = 0;
    right.z = get_z(hooks->matrix[0][hooks->width_grid - 1], hooks);
    top.x = 0;
    top.y = 0;
    top.z = get_z(hooks->matrix[0][0], hooks);
    bottom.x = hooks->width_grid * hooks->x_factor;
    bottom.y = hooks->height_grid * hooks->y_factor;
    bottom.z = get_z(hooks->matrix[hooks->height_grid - 1][hooks->width_grid - 1],
            hooks);
    hooks->x_offset = (WIDTH / 2);
    hooks->y_offset = (HEIGHT / 2);
}

int get_z(char *str, t_hooks *hooks)
{
    return (ft_atoi(str) * hooks->z_factor);
}

int get_color(char *str, t_hooks *hooks)
{
    char    *color;
    int     color_value;
    int     z;

    color = ft_strchr(str, ',');
    if (color)
    {
        color_value = atoi_base(color + 1, 16);
        return (color_value);
    }
    z = get_z(str, hooks);
    if (z < -10)
        return (LOW_LEVEL_COLOR);
    else if (z >= -10 && z <= 10)
        return (WHITE_COLOR);
    else
        return (HIGH_LEVEL_COLOR);
}

int is_center_point(t_hooks *hooks, int i, int j)
{
    if (hooks->width_grid % 2 == 0 && hooks->height_grid % 2 == 0)
        return (i == hooks->height_grid / 2 && j == hooks->width_grid / 2 - 1);
    else if (hooks->height_grid % 2 == 0 && hooks->width_grid % 2 != 0)
        return (i == hooks->height_grid / 2 && j == (hooks->width_grid / 2 - 1));
    else if (hooks->height_grid % 2 != 0 && hooks->width_grid % 2 == 0)
        return (i == hooks->height_grid / 2 - 1 && j == hooks->width_grid / 2);
    return (i == hooks->height_grid / 2 - 1 && j == hooks->width_grid / 2 - 1);
}

void    mark_points(t_hooks *hooks)
{
    int     i;
    int     j;
    t_point point;

    i = 0;
    while (i < hooks->height_grid)
    {
        j = 0;
        while (j < hooks->width_grid)
        {
            point.x = j * hooks->x_factor;
            point.y = i * hooks->y_factor;
            point.z = get_z(hooks->matrix[i][j], hooks);
            point.color = get_color(hooks->matrix[i][j], hooks);
            if (is_center_point(hooks, i, j))
                hooks->center_point = point;
            get_real_point(hooks, &point);
            put_the_pixel(&hooks->img, point.x, point.y, point.color);
            if (hooks->allow_link)
                link_point(hooks, i, j);
            j++;
        }
        i++;
    }
}
