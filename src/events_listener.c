/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_listener_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:19:57 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/26 15:58:16 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./events/events_bonus.h"
#include "./includes/header_bonus.h"

int	event_listener(int keycode, t_hooks *hooks)
{
	if (keycode == 17 && !hooks->cmd_mode && WIDTH > 500)
	{
		hooks->cmd_mode = !hooks->cmd_mode;
		show_input_label(hooks, keycode, 0);
		return (0);
	}
	if (command_line_handler(hooks, keycode) == 0)
		return (0);
	reset_exit_handler(hooks, keycode);
	link_cart_handler(hooks, keycode);
	handle_scaling(hooks, keycode);
	handle_moving(hooks, keycode);
	handle_z_scaling(hooks, keycode);
	handle_xy_scaling(hooks, keycode);
	view_handle(hooks, keycode);
	return (0);
}
