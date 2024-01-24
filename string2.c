#include "./includes/header.h"

int is_overflowed_int(char *str)
{
	int		res;
	char	*num;
	int		i;

	i = 0;
	res = ft_atoi(str);
	num = ft_itoa(res);
	if (str[0] == '+')
		i++;
	while (str[i] && str[i] != ',')
	{
		if (str[i] != num[i])
		{
			free(num);
			return (1);
		}
		i++;
	}
	free(num);
	return (0);
}

int	char_is_degits(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ',')
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

void	guide_helper(t_hooks *hooks, int *logo_width, int *logo_height)
{
	char	*data;

	if (HEIGHT < 230 || WIDTH < 350)
		return ;
	data = ft_itoa(hooks->width_grid * hooks->height_grid);
	mlx_string_put(hooks->mlx, hooks->win, 15, 10, WHITE_COLOR, "Points rendered: ");
	mlx_string_put(hooks->mlx, hooks->win, 200, 10, WHITE_COLOR, data);
	free(data);
	data = ft_itoa(hooks->scale);
	mlx_string_put(hooks->mlx, hooks->win, 15, 30, WHITE_COLOR, "Scale: ");
	mlx_string_put(hooks->mlx, hooks->win, 200, 30, WHITE_COLOR, data);
	free(data);
	data = ft_itoa(hooks->z_factor);
	mlx_string_put(hooks->mlx, hooks->win, 15, 50, WHITE_COLOR, "Z factor: ");
	mlx_string_put(hooks->mlx, hooks->win, 200, 50, WHITE_COLOR, data);
	free(data);
	hooks->logo = mlx_xpm_file_to_image(hooks->mlx, "./imgs/logo.xpm", logo_width, logo_height);
	mlx_put_image_to_window(hooks->mlx, hooks->win, hooks->logo, WIDTH - 115, -10);
	mlx_string_put(hooks->mlx, hooks->win, 15, 70, WHITE_COLOR, "Zoom: z/x");
	mlx_string_put(hooks->mlx, hooks->win, 15, 90, WHITE_COLOR, "Reset: r");
}

void	show_guide(t_hooks *hooks)
{
	int		logo_width;
	int		logo_height;
	char	*data;

	logo_height = 100;
	logo_width = 100;
	guide_helper(hooks, &logo_width, &logo_height);
	mlx_string_put(hooks->mlx, hooks->win, 15, 110, WHITE_COLOR, "Toggle linking: l");
	mlx_string_put(hooks->mlx, hooks->win, 200, 110, !hooks->allow_link ? RED_COLOR : GREEN_COLOR, !hooks->allow_link ? "off" : "on");
	mlx_string_put(hooks->mlx, hooks->win, 15, 130, WHITE_COLOR, "Top view(2D): f");
	mlx_string_put(hooks->mlx, hooks->win, 200, 130, !hooks->parallel_view ? RED_COLOR : GREEN_COLOR, !hooks->parallel_view ? "off" : "on");
	mlx_string_put(hooks->mlx, hooks->win, 15, 150, WHITE_COLOR, "Z scaling: j/k");
	mlx_string_put(hooks->mlx, hooks->win, 15, 170, WHITE_COLOR, "Z rotation: a/d");
	mlx_string_put(hooks->mlx, hooks->win, 15, 190, WHITE_COLOR, "Command line: c");
	mlx_string_put(hooks->mlx, hooks->win, 200, 190, !hooks->cmd_mode ? RED_COLOR : GREEN_COLOR, !hooks->cmd_mode ? "off" : "on");
	data = ft_itoa(hooks->z_angle);
	mlx_string_put(hooks->mlx, hooks->win, 15, 210, WHITE_COLOR, "Z angle: ");
	mlx_string_put(hooks->mlx, hooks->win, 200, 210, WHITE_COLOR, data);
	free(data);
	mlx_string_put(hooks->mlx, hooks->win, 15, 230, WHITE_COLOR, "Exit: esc");
}
