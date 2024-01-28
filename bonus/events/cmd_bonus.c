/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:07 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/28 00:38:04 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./events_bonus.h"

void	helper_cmd(t_hooks *hooks, int len)
{
	if (ft_strncmp(hooks->cmd, "zoomout", 7) == 0 && len == 7
		&& hooks->scale > .3)
		hooks->scale -= .2;
	else if (ft_strncmp(hooks->cmd, "zinc", 4) == 0 && len == 4)
		update_limit(&hooks->z_factor, 200, .5);
	else if (ft_strncmp(hooks->cmd, "zdec", 4) == 0 && len == 4)
		update_limit(&hooks->z_factor, -200, -.5);
	else if (ft_strncmp(hooks->cmd, "xinc", 4) == 0 && len == 4)
		update_limit(&hooks->x_factor, 200, .5);
	else if (ft_strncmp(hooks->cmd, "xdec", 4) == 0 && len == 4)
		update_limit(&hooks->x_factor, 0, -.5);
	else if (ft_strncmp(hooks->cmd, "yinc", 4) == 0 && len == 4)
		update_limit(&hooks->y_factor, 200, .5);
	else if (ft_strncmp(hooks->cmd, "ydec", 4) == 0 && len == 4)
		update_limit(&hooks->y_factor, 0, -.5);
	else if (ft_strncmp(hooks->cmd, "rotate", 6) == 0 && len == 6)
		animate_angle_update(&hooks->z_angle, 2);
	else if (ft_strncmp(hooks->cmd, "derotate", 8) == 0 && len == 8)
		animate_angle_update(&hooks->z_angle, -2);
	else if (ft_strncmp(hooks->cmd, "link", 4) == 0 && len == 4)
		hooks->allow_link = 1;
	else if (ft_strncmp(hooks->cmd, "unlink", 6) == 0 && len == 6)
		hooks->allow_link = 0;
}

void	execute_cmd(t_hooks *hooks)
{
	int	len;

	if (!hooks->cmd_mode)
		return ;
	len = (int)ft_strlen(hooks->cmd);
	if (ft_strncmp(hooks->cmd, "exit", 4) == 0 && len == 4)
		exit_free(hooks);
	else if (ft_strncmp(hooks->cmd, "parallel", 8) == 0 && len == 8)
		hooks->parallel_view = 1;
	else if (ft_strncmp(hooks->cmd, "isometric", 9) == 0 && len == 9)
		hooks->parallel_view = 0;
	else if (ft_strncmp(hooks->cmd, "left", 4) == 0 && len == 4)
		update_limit(&hooks->x_offset, -5000, -hooks->move_step);
	else if (ft_strncmp(hooks->cmd, "right", 5) == 0 && len == 5)
		update_limit(&hooks->x_offset, 5000, hooks->move_step);
	else if (ft_strncmp(hooks->cmd, "up", 2) == 0 && len == 2)
		update_limit(&hooks->y_offset, -5000, -hooks->move_step);
	else if (ft_strncmp(hooks->cmd, "down", 4) == 0 && len == 4)
		update_limit(&hooks->y_offset, 5000, hooks->move_step);
	else if (ft_strncmp(hooks->cmd, "zoomin", 6) == 0 && len == 6)
		update_limit(&hooks->scale, 10, .2);
	else
		helper_cmd(hooks, len);
}

void	show_input_label(t_hooks *hooks, int keycode, int allow)
{
	char	*tmp;
	char	*added;
	int		color;

	if (allow)
	{
		added = get_char(keycode);
		tmp = ft_strjoin(hooks->cmd, added);
		free(added);
		free(hooks->cmd);
		hooks->cmd = tmp;
	}
	render_next_frame(hooks);
	color = GREEN_COLOR;
	if ((int)ft_strlen(hooks->cmd) > 20)
		color = RED_COLOR;
	mlx_string_put(hooks->mlx, hooks->win, 20, HEIGHT - 40, color, ">");
	mlx_string_put(hooks->mlx, hooks->win, 40, HEIGHT - 40, WHITE_COLOR,
		hooks->cmd);
}

int	delete_last_char(t_hooks *hooks, int keycode)
{
	char	*tmp;

	tmp = ft_substr(hooks->cmd, 0, ft_strlen(hooks->cmd) - 1);
	free(hooks->cmd);
	hooks->cmd = tmp;
	show_input_label(hooks, keycode, 0);
	return (0);
}

int	command_line_handler(t_hooks *hooks, int keycode)
{
	if (!hooks->cmd_mode)
		return (1);
	if (ft_strlen(hooks->cmd) > 20 && keycode != 51)
		return (0);
	if (keycode == 53)
	{
		free(hooks->cmd);
		hooks->cmd = ft_strdup("");
		hooks->cmd_mode = 0;
		render_next_frame(hooks);
		return (0);
	}
	if (keycode == 51)
		return (delete_last_char(hooks, keycode));
	show_input_label(hooks, keycode, 1);
	if (hooks->cmd_mode && keycode == 36)
	{
		execute_cmd(hooks);
		free(hooks->cmd);
		hooks->cmd = ft_strdup("");
		render_next_frame(hooks);
		show_input_label(hooks, keycode, 0);
		return (0);
	}
	return (0);
}
