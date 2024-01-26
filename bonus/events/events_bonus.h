/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:00:34 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/26 22:04:58 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_BONUS_H
# define EVENTS_BONUS_H

# include "../includes/header_bonus.h"

int		event_listener(int keycode, t_hooks *hooks);
void	animate_angle_update(double *angle, double step);
void	update_limit(double *ptr, double limit, double value);
int		command_line_handler(t_hooks *hooks, int keycode);
void	show_input_label(t_hooks *hooks, int keycode, int allow);
void	execute_cmd(t_hooks *hooks);
int		render_next_frame(t_hooks *hooks);
void	reset(t_hooks *hooks);
void	reset_exit_handler(t_hooks *hooks, int keycode);
void	link_cart_handler(t_hooks *hooks, int keycode);
void	handle_moving(t_hooks *hooks, int keycode);
void	handle_scaling(t_hooks *hooks, int keycode);
void	view_handle(t_hooks *hooks, int keycode);
void	handle_z_scaling(t_hooks *hooks, int keycode);
void	handle_xy_scaling(t_hooks *hooks, int keycode);

#endif