/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_sides_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:41:59 by abchikhi          #+#    #+#             */
/*   Updated: 2024/01/28 00:32:06 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header_bonus.h"

void	render_top_left(t_hooks *hooks)
{
	hooks->direction.i_start = 0;
	hooks->direction.i_end = hooks->height_grid;
	hooks->direction.i_step = 1;
	hooks->direction.j_start = 0;
	hooks->direction.j_end = hooks->width_grid;
	hooks->direction.j_step = 1;
}

void	render_top_right(t_hooks *hooks)
{
	hooks->direction.i_start = 0;
	hooks->direction.i_end = hooks->height_grid;
	hooks->direction.i_step = 1;
	hooks->direction.j_start = hooks->width_grid - 1;
	hooks->direction.j_end = -1;
	hooks->direction.j_step = -1;
}

void	render_bottom_left(t_hooks *hooks)
{
	hooks->direction.i_start = hooks->height_grid - 1;
	hooks->direction.i_end = -1;
	hooks->direction.i_step = -1;
	hooks->direction.j_start = 0;
	hooks->direction.j_end = hooks->width_grid;
	hooks->direction.j_step = 1;
}

void	render_bottom_right(t_hooks *hooks)
{
	hooks->direction.i_start = hooks->height_grid - 1;
	hooks->direction.i_end = -1;
	hooks->direction.i_step = -1;
	hooks->direction.j_start = hooks->width_grid - 1;
	hooks->direction.j_end = -1;
	hooks->direction.j_step = -1;
}
