#include "./includes/header.h"

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
        color_value = atoi_hexa(color + 3);
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
            point.x = j * (WIDTH / hooks->width_grid / 2);
            point.y = i * (WIDTH / hooks->height_grid / 2);
            point.z = get_z(hooks->matrix[i][j], hooks);
            point.color = get_color(hooks->matrix[i][j], hooks);
            cartesian(hooks,
                point.x, point.y,
                point.z, point.color);
            if (hooks->allow_link)
                link_point(hooks, i, j);
            j++;
        }
        i++;
    }
}
