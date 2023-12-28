#ifndef HEADER_H
# define HEADER_H

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
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
	char		***matrix;
	t_point		*space_points;
	t_grid		grid;
	double		base_cartis[6];
}	t_hooks;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void    *ft_realloc(void *ptr, size_t old_size, size_t size);
void    ft_free(void    **ptr);

void	put_the_pixel(t_data *img, int x, int y, int color);
int 	load_map(t_hooks *hooks, char *file, t_grid *grid);
void    free_matrix(t_hooks *hooks);

/*points list*/
t_point		*new_point(int x, int y, int z);
void		add_point(t_point **point, t_point *new);
t_point 	*copy_point_list(t_point *source);
void    	mark_points(t_point **point, t_data *img, t_hooks *hooks);

/*draw*/
void		draw_line(t_data *img, t_hooks *hooks, t_point *start, t_point *end, int color);

void		cartesian(t_data *img, t_hooks *hooks, int x, int y, int z, int color);
void    	draw_cartesian(t_data *img, t_hooks *hooks);

#endif