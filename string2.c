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

void	guide_helper(t_hooks *hooks)
{
	char	*str;
	char	*data;

	if (HEIGHT < 230)
		return ;
	data = ft_itoa(hooks->width_grid * hooks->height_grid);
	str = ft_strjoin("Points rendered: ", data);
	mlx_string_put(hooks->mlx, hooks->win, 15, 10, 0x00FFFFFF, str);
	free(data);
	free(str);
	data = ft_itoa(hooks->scale);
	str = ft_strjoin("Scale: ", data);
	mlx_string_put(hooks->mlx, hooks->win, 15, 30, 0x00FFFFFF, str);
	free(data);
	free(str);
	data = ft_itoa(hooks->z_factor);
	str = ft_strjoin("Z factor: ", data);
	mlx_string_put(hooks->mlx, hooks->win, 15, 50, 0x00FFFFFF, str);
	free(data);
	free(str);
}

void	show_guide(t_hooks *hooks)
{
	int		logo_width;
	int		logo_height;

	guide_helper(hooks);
	mlx_string_put(hooks->mlx, hooks->win, 15, 70, 0x00FFFFFF, "Zoom: z/x");
	mlx_string_put(hooks->mlx, hooks->win, 15, 90, 0x00FFFFFF, "Reset: r");
	mlx_string_put(hooks->mlx, hooks->win, 15, 110, 0x00FFFFFF, "Dots view: l (on/off)");
	mlx_string_put(hooks->mlx, hooks->win, 15, 130, 0x00FFFFFF, "Show cartesian: c (on/off)");
	mlx_string_put(hooks->mlx, hooks->win, 15, 150, 0x00FFFFFF, "Top view(2D): f");
	mlx_string_put(hooks->mlx, hooks->win, 15, 170, 0x00FFFFFF, "Exit: esc");
	logo_height = 100;
	logo_width = 100;
	hooks->logo = mlx_xpm_file_to_image(hooks->mlx, "./imgs/logo.xpm", &logo_width, &logo_height);
	mlx_put_image_to_window(hooks->mlx, hooks->win, hooks->logo, WIDTH - 115, -10);
}
