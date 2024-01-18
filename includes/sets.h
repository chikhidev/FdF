#ifndef SETS_H
# define SETS_H

# define HEIGHT 1000
# define WIDTH 1800
# define DEFAULT_ANGLE 35
# define AXIS_LENGTH 300
# define WINDOW_NAME "FdF"

# define X_OFFSET (WIDTH/2)
# define Y_OFFSET (HEIGHT/2)

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

# define RED_COLOR 0xFF5733
# define BLUE_COLOR 0x33BBFF
# define GREEN_COLOR 0x3FF86
# define WHITE_COLOR 0xFFFFFF
# define HIGH_LEVEL_COLOR 0x00FFC5
# define LOW_LEVEL_COLOR 0x0075A2

# define Z_MOY 40

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_hooks
{
	t_data		img;
	void		*mlx;
	void		*win;
	char		***matrix;
	char		**arr;
	void		*logo;
	char		*tmp_string;
	int			width_grid;
	int			height_grid;
	int			z_max;
	int			z_min;
	double		z_factor;
	double		x_factor;
	double		y_factor;
	double		base_cartis[6];
	double		scale;
	int 		x_center;
	int 		y_center;
	int 		x_offset;
	int 		y_offset;
	int			allow_link;
	double		move_step;
	int			most_left_x;
	int			most_right_x;
	int			most_top_y;
	int			most_bottom_y; 
}	t_hooks;

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
