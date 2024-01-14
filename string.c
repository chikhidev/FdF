#include "./includes/header.h"

int	cols_count(char **arr, t_hooks *hooks)
{
	int	i;
	int	z_value;

	i = 0;
	while (arr[i])
	{
		//5 8 0 4,0xFF0000
		if (!ft_isdigit(arr[i][0]) && arr[i][0] != '-' && arr[i][0] != '+')
		{
			ft_printf("Invalid syntax, line %d\n", 1, hooks->height_grid + 1);
			exit(1);
		}
		z_value = ft_atoi(arr[i]);
		if (hooks->height_grid == 0 && i == 0)
		{
			hooks->z_min = z_value;
			hooks->z_max = z_value;
		}
		else
		{
			if (z_value > hooks->z_max)
				hooks->z_max = z_value;
			if (z_value < hooks->z_min)
				hooks->z_min = z_value;
		}
		i++;
	}
	return (i);
}

int	atoi_hexa(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] && str[i] != ',')
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 16 + str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = res * 16 + str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = res * 16 + str[i] - 'a' + 10;
		else
			return (0);
		i++;
	}
	return (res);
}

void	show_guide(t_hooks *hooks)
{
	char	*str;

	if (HEIGHT < 230)
		return ;
	str = ft_strjoin("Points rendered: ", ft_itoa(
		hooks->width_grid * hooks->height_grid)
	);
	mlx_string_put(hooks->mlx, hooks->win, 15, 10, 0x00FFFFFF, str);
	free(str);
	str = ft_strjoin("Scale: ", ft_itoa(hooks->scale));
	mlx_string_put(hooks->mlx, hooks->win, 15, 110, 0x00FFFFFF, str);
	free(str);
	str = ft_strjoin("Z factor: ", ft_itoa(hooks->z_factor));
	mlx_string_put(hooks->mlx, hooks->win, 15, 30, 0x00FFFFFF, str);
	free(str);
	str = ft_strjoin("X angle: ", ft_itoa(hooks->x_angle));
	mlx_string_put(hooks->mlx, hooks->win, 15, 50, 0x00FFFFFF, str);
	free(str);
	str = ft_strjoin("Y angle: ", ft_itoa(hooks->y_angle));
	mlx_string_put(hooks->mlx, hooks->win, 15, 70, 0x00FFFFFF, str);
	free(str);
	mlx_string_put(hooks->mlx, hooks->win, 15, 90, 0x00FFFFFF, "Zoom: z/x");
	mlx_string_put(hooks->mlx, hooks->win, 15, 130, 0x00FFFFFF, "Reset: r");
	mlx_string_put(hooks->mlx, hooks->win, 15, 170, 0x00FFFFFF, "Dots view: l (on/off)");
	mlx_string_put(hooks->mlx, hooks->win, 15, 150, 0x00FFFFFF, "Show cartesian: c (on/off)");
	mlx_string_put(hooks->mlx, hooks->win, 15, 190, 0x00FFFFFF, "Exit: esc");
}

int	valid_extention(char	*name)
{
	char	*extention;

	extention = ft_strrchr(name, '.');
	if (!extention)
		print_error("No extention found\n", 1);
	return (ft_strncmp(extention, ".fdf", 4) == 0);
}