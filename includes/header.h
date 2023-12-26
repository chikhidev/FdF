#ifndef HEADER_H
# define HEADER_H

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "sets.h"
#include "geo.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_display
{
	void		*mlx;
	void		*win;
}	t_display;

typedef struct s_grid
{
	int	width_grid;
	int	height_grid;
}	t_grid;

typedef struct s_hooks
{
	int			*error;
	int			***matrix;
	t_grid		grid;
}	t_hooks;

void	put_the_pixel(t_data *img, int x, int y, int color);
int		get_matrix(t_hooks *hooks, char *file, t_grid *grid);

/*points list*/
t_point		*new_point(int x, int y, int z);
void		add_point(t_point **point, t_point *new);
void		clean_points(t_point **point);
void		mark_points(t_point **point, t_data *img, int color);
t_point		*generate_random_points(int n);

/*draw*/
void		generate_map(t_hooks *hooks, t_data *img);
void		draw_line(t_data *img, t_point *start, t_point *end);

void    	cartesian(t_data *img, int x, int y, int color);
void    	draw_cartesian_axis(t_data *img);

#endif
