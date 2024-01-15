#include "./includes/header.h"

void	config_hooks(t_hooks *hooks)
{
	hooks->scale = .8;
	hooks->x_offset = 0;
	hooks->y_offset = 0;
	hooks->y_angle = 0;
	hooks->x_angle = 0;
	hooks->allow_link = 1;
	if (hooks->width_grid != 0 && hooks->height_grid != 0)
	{
		hooks->x_factor = WIDTH / hooks->width_grid / 2;
		hooks->y_factor = WIDTH / hooks->height_grid / 2;
	}
	hooks->base_cartis[0] = 1;
	hooks->base_cartis[1] = .333;
	hooks->base_cartis[2] = -1;
	hooks->base_cartis[3] = .333;
	hooks->base_cartis[4] = 0;
	hooks->base_cartis[5] = -1;
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