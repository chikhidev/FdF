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

void    clean_points(t_point **point)
{
    t_point	*tmp;

    while (*point)
    {
        tmp = *point;
        *point = (*point)->next;
        free(tmp);
    }
}

void    mark_points(t_point **point, t_data *img, int color)
{
    t_point	*tmp;

    tmp = *point;
    while (tmp)
    {
        put_the_pixel(img, tmp->x, tmp->y, color);
        tmp = tmp->next;
    }
}

// t_point *generate_random_points(int n)
// {
//     t_point	*point;
//     int		i;

//     point = NULL;
//     i = 0;
//     while (i < n)
//     {
//         add_point(&point, new_point(rand() % (WIDTH), rand() % (HEIGHT), 0));
//         i++;
//     }
//     return (point);
// }