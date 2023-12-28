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

int     shouldbe_linked(t_point *p1, t_point *p2)
{
    return (
        (p1->x == p2->x && p1->y == p2->y) ||
        (p1->y == p2->y && p1->z == p2->z) ||
        (p1->x == p2->x && p1->z == p2->z) ||
        (p1->x == p2->x && p1->y == p2->y && p1->z == p2->z)
    );
}

void    link_points(t_point **point, t_hooks *hooks, t_data *img, int color)
{
    t_point	*tmp;
    t_point *looking_for;

    tmp = *point;
    while (tmp->next)
    {
        printf("<Point> [%d, %d, %d]\n", tmp->x, tmp->y, tmp->z);
        looking_for = *point;
        while (looking_for)
        {
            if (
                shouldbe_linked(tmp, looking_for) &&
                looking_for != tmp)
            {
                // printf("[DEBUG]: link [%d, %d, %d] to [%d, %d, %d]\n", 
                //     tmp->x, tmp->y, tmp->z,
                //     looking_for->x, looking_for->y, looking_for->z 
                // );
                draw_line(img, hooks, tmp, looking_for, color);
            }
            looking_for = looking_for->next;
        }
        tmp = tmp->next;
    }
}

void    mark_points(t_point **point, t_data *img, t_hooks *hooks, int color)
{
    t_point	*tmp;

    tmp = *point;
    while (tmp)
    {
        cartesian(img, hooks, tmp->x, tmp->y, tmp->z, color);
        tmp = tmp->next;
    }
    link_points(point, hooks, img, color);
}

t_point *copy_point_list(t_point *source)
{
    t_point *copy = NULL;
    t_point *current = source;

    while (current)
    {
        add_point(&copy, new_point(current->x, current->y, current->z));
        current = current->next;
    }

    return copy;
}
