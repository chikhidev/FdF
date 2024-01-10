#ifndef HEADER_H
# define HEADER_H

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include "./sets.h"
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "sets.h"
#include "geo.h"

/*error handling*/
int			print_error(const char *message, int error_signal);
void	    exit_free(t_hooks *hooks);

/*helpers funcs*/
void    	*ft_realloc(void *ptr, size_t old_size, size_t size);
void    	ft_free(void    **ptr);
void    	free_matrix(char ***matrix, t_hooks *hooks);
int			atoi_hexa(char *str);
int 		get_z(char *str, t_hooks *hooks);
int 		get_color(char *str, t_hooks *hooks);
int	    	cols_count(char **arr, t_hooks *hooks);
void	    show_guide(t_hooks *hooks);

/**/
void		put_the_pixel(t_data *img, int x, int y, int color);
int 		load_map(t_hooks *hooks, char *file);

/*points matrix*/
void    	mark_points(t_hooks *hooks);

/*draw*/
void 		link_point(t_hooks *hooks, int row, int col);

/*cartisian*/
void		cartesian(t_hooks *hooks, int x, int y, int z, int color);
void    	draw_cartesian(t_hooks *hooks);

/*events*/
int	        key_listener(int keycode, t_hooks *hooks);
int         zoom_handle(int keycode, t_hooks *hooks);
void        rotate_x(t_hooks *hooks, double angle);
void        refresh_image(t_hooks *hooks, t_data *img);
void        config_hooks(t_hooks *hooks);

#endif
