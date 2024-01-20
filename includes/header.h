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

void	    _setup_(t_hooks *hooks);
void	    config_hooks(t_hooks *hooks);
void        refresh_image(t_hooks *hooks, t_data *img);
void        center_map(t_hooks *hooks);

void        render_top_left(t_hooks *hooks);
void        render_top_right(t_hooks *hooks);
void        render_bottom_left(t_hooks *hooks);
void        render_bottom_right(t_hooks *hooks);

int         print_error(const char *message, int error_signal);
void	    exit_free(t_hooks *hooks);
int	        valid_extention(char	*name);

void    	free_matrix(t_hooks *hooks);
void        free_split(char **splitted);
void        exit_free(t_hooks *hooks);
int         destroy(int keycode, t_hooks *hooks);

int         is_overflowed_int(char *str);
int         char_is_degits(char *str);
int	        atoi_base(char *str, int base);
int 		get_z(char *str, t_hooks *hooks);
int 		get_color(char *str, t_hooks *hooks);
int	    	cols_count(char **arr, t_hooks *hooks);
void	    show_guide(t_hooks *hooks);

void		put_the_pixel(t_data *img, int x, int y, int color);
int 		load_map(t_hooks *hooks, char *file);

void 		link_point(t_hooks *hooks, int row, int col);
void    	mark_points(t_hooks *hooks);

void        cartesian(t_hooks *hooks, t_point *point);
int         get_real_x(t_hooks *hooks, t_point *point);
int         get_real_y(t_hooks *hooks, t_point *point);
void        get_real_point(t_hooks *hooks, t_point *point);

#endif
