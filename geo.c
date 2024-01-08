#include "./includes/header.h"

int get_z(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != ',')
        i++;
    return (ft_atoi(str));
}

int get_color(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != ',')
        i++;
    if (str[i] == ',')
        return (atoi_hexa(str + i + 1));
    return (0xFFFFFF);
}

// void    link_points(t_point **point, t_hooks *hooks, t_data *img)
// {
//     t_point	*tmp;
//     t_point *looking_for;

//     tmp = *point;
//     while (tmp->next)
//     {
//         looking_for = *point;
//         while (looking_for)
//         {
//             if (shouldbe_linked(tmp, looking_for, hooks) &&
//                 looking_for != tmp)
//             {
//                 draw_line(img, hooks, tmp, looking_for, 0xFFFFFF);
//             }
//             looking_for = looking_for->next;
//         }
//         tmp = tmp->next;
//     }
// }

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
    int i;
    int j;

    i = 0;
    while (i < hooks->grid.height_grid)
    {
        j = 0;
        while (j < hooks->grid.width_grid)
        {
            cartesian(img, hooks,
                j * ( WIDTH / hooks->grid.width_grid / 2),
                i * ( WIDTH / hooks->grid.height_grid / 2), 
                get_z(hooks->matrix[i][j]),
                get_color(hooks->matrix[i][j]));
            j++;
        }
        i++;
    }
    // link_points(point, hooks, img);
}
