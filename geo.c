#include "./includes/header.h"

t_point    *new_point(int x, int y, int z)
{
    t_point	*point;

    point = malloc(sizeof(t_point));
    point->x = x;
    point->y = y;
    point->z = z;
    point->next = NULL;
    return (point);
}

void    add_point(t_point **point, t_point *new)
{
    t_point	*tmp;

    if (!*point)
    {
        *point = new;
        return ;
    }
    tmp = *point;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

int     shouldbe_linked(t_point *p1, t_point *p2, t_hooks *hooks)
{
    int unit;

    unit = WIDTH / hooks->grid.width_grid / 3;
    return (
        ((p1->x == p2->x) ||
        (p1->y == p2->y) ||
        (p1->x == p2->x && p1->z == p2->z) ||
        (p1->y == p2->y && p1->z == p2->z))&&
        (
            (p1->x / unit == (p2->x / unit) - 1) ||
            (p1->x / unit == (p2->x / unit) + 1) ||
            (p1->y / unit == (p2->y / unit) - 1) ||
            (p1->y / unit == (p2->y / unit) + 1) ||
            (p1->z / unit == (p2->z / unit) - 1) ||
            (p1->z / unit == (p2->z / unit) + 1)
        )
    );
}


// int     shouldbe_linked(t_point *p1, t_point *p2, t_hooks *hooks)
// {
//     int unit;

//     unit = WIDTH / hooks->grid.width_grid / 3;
//     return (
//             (
//                 (p1->y == p2->y ) ||
//                 (p1->x == p2->x ) || 
//                 (p1->z == p2->z )
//             )
//             &&
//         (
//             (p1->x / unit == (p2->x / unit) - 1) ||
//             (p1->x / unit == (p2->x / unit) + 1) ||
//             (p1->y / unit == (p2->y / unit) - 1) ||
//             (p1->y / unit == (p2->y / unit) + 1) ||
//             (p1->z / unit == (p2->z / unit) - 1) ||
//             (p1->z / unit == (p2->z / unit) + 1)
//         )
//     );
// }

void    link_points(t_point **point, t_hooks *hooks, t_data *img, int color)
{
    t_point	*tmp;
    t_point *looking_for;

    tmp = *point;
    while (tmp->next)
    {
        looking_for = *point;
        while (looking_for)
        {
            if (shouldbe_linked(tmp, looking_for, hooks) &&
                looking_for != tmp)
            {
                draw_line(img, hooks, tmp, looking_for, color);
                printf("point[%d, %d, %d] -> point[%d, %d, %d]\n",
                    tmp->x, tmp->y, tmp->z,
                    looking_for->x, looking_for->y, looking_for->z
                );
            }
            looking_for = looking_for->next;
        }
        tmp = tmp->next;
    }
}

void    mark_points(t_point **point, t_data *img, t_hooks *hooks)
{
    t_point	*tmp;
    int     color;

    tmp = *point;
    while (tmp)
    {
        if (tmp->z > 0)
            color = HIGHT_LEVEL_COLOR;
        else if (tmp->z < 0)
            color = LOW_LEVEL_COLOR;
        else
            color = WHITE_COLOR;
        cartesian(img, hooks, tmp->x, tmp->y, tmp->z, color);
        tmp = tmp->next;
    }
    // link_points(point, hooks, img, color);
}

void    clean_points(t_hooks *hooks)
{
    t_point *current = hooks->space_points;
    t_point *temp;

    while (current)
    {
        temp = current->next;
        ft_free((void **)&current);
        current = temp;
    }
}
