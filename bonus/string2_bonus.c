/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:59:20 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/26 22:46:12 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header_bonus.h"

int	is_overflowed_int(char *str)
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
	mlx_string_put(hooks->mlx, hooks->win, 15, 10, WHITE_COLOR,
		"Points rendered: ");
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
	hooks->logo = mlx_xpm_file_to_image(hooks->mlx, "./imgs/logo.xpm",
			logo_width, logo_height);
	mlx_put_image_to_window(hooks->mlx, hooks->win, hooks->logo, WIDTH - 115,
		-10);
	mlx_string_put(hooks->mlx, hooks->win, 15, 70, WHITE_COLOR, "Zoom: z/x");
	mlx_string_put(hooks->mlx, hooks->win, 15, 90, WHITE_COLOR, "Reset: r");
	mlx_string_put(hooks->mlx, hooks->win, 15, 110, WHITE_COLOR,
		"Toggle linking: l");
}

void	guide_helper2(t_hooks *hooks)
{
	char	*toggle;
	int		color;

	toggle = "off";
	if (hooks->allow_link)
		toggle = "on";
	color = RED_COLOR;
	if (hooks->allow_link)
		color = GREEN_COLOR;
	mlx_string_put(hooks->mlx, hooks->win, 200, 110, color, toggle);
	toggle = "off";
	if (hooks->parallel_view)
		toggle = "on";
	color = RED_COLOR;
	if (hooks->parallel_view)
		color = GREEN_COLOR;
	mlx_string_put(hooks->mlx, hooks->win, 200, 130, color, toggle);
	toggle = "off";
	if (hooks->cmd_mode)
		toggle = "on";
	color = RED_COLOR;
	if (hooks->cmd_mode)
		color = GREEN_COLOR;
	mlx_string_put(hooks->mlx, hooks->win, 200, 190, color, toggle);
}

void	show_guide(t_hooks *hooks)
{
	int		logo_width;
	int		logo_height;
	char	*data;

	logo_height = 100;
	logo_width = 100;
	guide_helper(hooks, &logo_width, &logo_height);
	guide_helper2(hooks);
	mlx_string_put(hooks->mlx, hooks->win, 15, 150, WHITE_COLOR,
		"Z scaling: j/k");
	mlx_string_put(hooks->mlx, hooks->win, 15, 170, WHITE_COLOR,
		"Z rotation: a/d");
	mlx_string_put(hooks->mlx, hooks->win, 15, 190, WHITE_COLOR,
		"Command line: t");
	mlx_string_put(hooks->mlx, hooks->win, 15, 130, WHITE_COLOR,
		"Top view(2D): f");
	data = ft_itoa(hooks->z_angle);
	mlx_string_put(hooks->mlx, hooks->win, 15, 210, WHITE_COLOR, "Z angle: ");
	mlx_string_put(hooks->mlx, hooks->win, 200, 210, WHITE_COLOR, data);
	free(data);
	mlx_string_put(hooks->mlx, hooks->win, 15, 230, WHITE_COLOR, "Exit: esc");
}
