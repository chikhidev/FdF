#ifndef VECTORS_H
#define VECTORS_H

typedef struct s_point
{
    int	x;
    int	y;
    int	z;
    int color;
    struct s_point *next;
}	t_point;

#endif