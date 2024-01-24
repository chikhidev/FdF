#include "./includes/header.h"

void	_setup_(t_hooks *hooks)
{
	hooks->width_grid = 0;
	hooks->height_grid = 0;
	hooks->z_max = 0;
	hooks->z_min = 0;
}

void	config_hooks(t_hooks *hooks)
{
	hooks->cmd = ft_strdup("");
	hooks->cmd_mode = 0;
	hooks->parallel_view = 0;
	hooks->scale = .3;
	hooks->x_offset = 0;
	hooks->y_offset = 0;
	hooks->allow_link = 1;
	hooks->move_step = 25;
	hooks->z_angle = 0;
	if (hooks->width_grid != 0 && hooks->height_grid != 0)
	{
		hooks->x_factor = WIDTH / hooks->width_grid / 3;
		hooks->y_factor = WIDTH / hooks->height_grid / 3;
	}
}

void refresh_image(t_hooks *hooks, t_data *img)
{
	img->img = mlx_new_image(hooks->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(
							img->img,
							&img->bits_per_pixel,
							&img->line_length,
							&img->endian
						);
	hooks->img = *img;
}