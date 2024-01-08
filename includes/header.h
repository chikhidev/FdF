#ifndef HEADER_H
# define HEADER_H

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
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
	char		***matrix;
	char		*tmp_string;
	char		**arr;
	t_grid		grid;
	double		base_cartis[6];
}	t_hooks;

/*error handling*/
int			print_error(const char *message, int error_signal);

/*helpers funcs*/
void    	*ft_realloc(void *ptr, size_t old_size, size_t size);
void    	ft_free(void    **ptr);
void    	free_matrix(char ***matrix, t_hooks *hooks);
int			atoi_hexa(char *str);
int			get_z(char *str);
int 		get_color(char *str);

/**/
void		put_the_pixel(t_data *img, int x, int y, int color);
int 		load_map(t_hooks *hooks, char *file, t_grid *grid);

/*points matrix*/
void    	mark_points(t_data *img, t_hooks *hooks);

/*draw*/
void 		link_point(t_data *img, t_hooks *hooks, int row, int col);

/*cartisian*/
void		cartesian(t_data *img, t_hooks *hooks, int x, int y, int z, int color);
void    	draw_cartesian(t_data *img, t_hooks *hooks);

#endif
