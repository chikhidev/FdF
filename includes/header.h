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
#include "vector.h"

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

/*drawing*/
void	draw_line(t_data *img, t_vector *vector, int color, int angle);

#endif
