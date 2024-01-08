#include "./includes/header.h"

int get_z(char *str)
{
    return (ft_atoi(str));
}

int get_color(char *str)
{
    char    *color;
    int     z;

    color = ft_strchr(str, ',');
    if (color)
        return (atoi_hexa(color + 1));
    z = get_z(str);
    if (z < -10)
        return (LOW_LEVEL_COLOR);
    else if (z >= -10 && z <= 10)
        return (WHITE_COLOR);
    else
        return (HIGHT_LEVEL_COLOR);
}

// void    generate_line(t_hooks *hooks, int line, t_point **tracking_point)
// {
//     int     j;
    
//     j = 0;
//     while (j < hooks->grid.width_grid)
//     {
//         add_point(tracking_point, new_point(
//             j * ( WIDTH / hooks->grid.width_grid / 2),
//             line * ( WIDTH / hooks->grid.height_grid / 2), 
//             ft_atoi(hooks->arr[j])));
//         j++;
//     }
// }

void    mark_points(t_data *img, t_hooks *hooks)
{
    int     i;
    int     j;
    t_point point;

    i = 0;
    while (i < hooks->grid.height_grid)
    {
        j = 0;
        while (j < hooks->grid.width_grid)
        {
            point.x = j * ( WIDTH / hooks->grid.width_grid / 2);
            point.y = i * ( WIDTH / hooks->grid.height_grid / 2);
            point.z = get_z(hooks->matrix[i][j]);
            point.color = get_color(hooks->matrix[i][j]);
            cartesian(img, hooks,
                point.x,
                point.y,
                point.z,
                point.color);
            // if (i < hooks->grid.height_grid - 1 && j < hooks->grid.width_grid - 1)
            //     link_point(img, hooks, i, j);
            j++;
        }
        i++;
    }
    // link_points(point, hooks, img);
}
