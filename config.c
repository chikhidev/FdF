#include "./includes/header.h"

void	config_hooks(t_hooks *hooks)
{
	hooks->z_max = 0;
	hooks->z_min = 0;
	hooks->scale = .8;
	hooks->x_offset = 0;
	hooks->y_offset = 0;
	hooks->y_angle = 0;
	hooks->x_angle = 0;
	hooks->allow_link = 1;
	hooks->z_factor = 50;
	/*
		(1,0,0) → (a,b) (0,1,0) → (c,d) (0,0,1) → (e,f)
	*/
	hooks->base_cartis[0] = 1;		/*a*/
	hooks->base_cartis[1] = .333;	/*b*/
	
	hooks->base_cartis[2] = -1;		/*c*/
	hooks->base_cartis[3] = .333;	/*d*/
	
	hooks->base_cartis[4] = 0;		/*e*/
	hooks->base_cartis[5] = -1;		/*f*/
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