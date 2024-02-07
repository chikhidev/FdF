/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:26 by abchikhi          #+#    #+#             */
/*   Updated: 2024/02/06 23:19:04 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./events_bonus.h"

void	update_limit(double *ptr, double limit, double value)
{
	if (limit > 0)
	{
		if (*ptr < limit)
			*ptr += value;
	}
	else
	{
		if (*ptr > limit)
			*ptr += value;
	}
}

void	reset(t_hooks *hooks)
{
	free(hooks->cmd);
	config_hooks(hooks);
	center_map(hooks);
	hooks->z_factor = 5;
}

void	reset_exit_handler(t_hooks *hooks, int keycode)
{
	if (keycode == 53 && !hooks->cmd_mode)
	{
		ft_printf("Bye\n");
		exit_free(hooks);
	}
	else if (keycode == 53 && hooks->cmd_mode)
	{
		free(hooks->cmd);
		hooks->cmd = ft_strdup("");
		hooks->cmd_mode = 0;
	}
	else if (keycode == 15)
	{
		reset(hooks);
		render_next_frame(hooks);
	}
}

void	link_cart_handler(t_hooks *hooks, int keycode)
{
	if (keycode == 37)
		hooks->allow_link = !hooks->allow_link;
	else
		return ;
	render_next_frame(hooks);
}