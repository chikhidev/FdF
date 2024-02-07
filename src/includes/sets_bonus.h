/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:02:15 by abchikhi          #+#    #+#             */
/*   Updated: 2024/02/06 20:36:16 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETS_BONUS_H
# define SETS_BONUS_H

# define HEIGHT 1000
# define WIDTH 1500
# define WINDOW_NAME "FdF"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

# define RED_COLOR 0xFF5733
# define BLUE_COLOR 0x33BBFF
# define GREEN_COLOR 0x3FF86
# define WHITE_COLOR 0xFFFFFF
# define HIGH_LEVEL_COLOR 0xffc61a
# define LOW_LEVEL_COLOR 0x0075Aa2

#define BACKGROUND_TOP 0xb2b4dd

# define Z_MOY 40

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct direction
{
	int			i_start;
	int			i_end;
	int			i_step;
	int			j_start;
	int			j_end;
	int			j_step;
}				t_direction;

typedef struct s_alphabet
{
	int			code;
	char		*content;
}				t_alphabet;

typedef struct s_hooks
{
	t_data		img;
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	char		***matrix;
	char		**arr;
	void		*logo;
	char		*tmp_string;
	int			width_grid;
	int			height_grid;
	t_direction	direction;
	t_point		center_point;
	int			z_max;
	int			z_min;
	double		z_factor;
	double		x_factor;
	double		y_factor;
	double		scale;
	double		facing_angle;
	double		x_offset;
	double		y_offset;
	int			allow_link;
	double		move_step;
	int			most_left_x;
	int			most_right_x;
	int			most_top_y;
	int			most_bottom_y;
	double		z_angle;
	int			parallel_view;
	int			cmd_mode;
	char		*cmd;
}				t_hooks;

typedef struct s_map_edges
{
	t_point		left;
	t_point		right;
	t_point		top;
	t_point		bottom;
}				t_map_edges;

typedef struct s_drawer
{
	int			steps;
	double		x_inc;
	double		y_inc;
	double		x;
	double		y;
	double		i;
}				t_drawer;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

#endif
