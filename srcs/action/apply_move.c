/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:42:51 by ktada             #+#    #+#             */
/*   Updated: 2022/11/17 18:38:59 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_vector	*get_move_diff(t_state *state, \
		double move_horizontal, double move_vertical)
{
	t_vector	*x_vec;
	t_vector	*y_vec;
	t_vector	*move_diff;

	x_vec = make_vector(0, -1);
	y_vec = make_vector(1, 0);
	set_rotate(x_vec, state->player_angle);
	set_rotate(y_vec, state->player_angle);
	scalar_mul_assign(x_vec, move_horizontal);
	scalar_mul_assign(y_vec, -move_vertical);
	move_diff = add(x_vec, y_vec);
	move_diff->y *= -1;
	free(x_vec);
	free(y_vec);
	return (move_diff);
}

//todo
static t_vector	*get_ideal_move_diff(t_state *state)
{
	double	move_horizontal;
	double	move_vertical;

	move_horizontal = 0;
	move_vertical = 0;
	if (state->press_key_left)
		move_horizontal -= MOVE_RATE;
	if (state->press_key_up)
		move_vertical -= MOVE_RATE;
	if (state->press_key_right)
		move_horizontal += MOVE_RATE;
	if (state->press_key_down)
		move_vertical += MOVE_RATE;
	return (get_move_diff(state, move_horizontal, move_vertical));
}

static bool	try_move_add2(t_state *state, double x, double y)
{
	x += state->player_pos->x;
	y += state->player_pos->y;
	if (has_wall_at_near2(state, x, y))
		return (false);
	state->player_pos->x = x;
	state->player_pos->y = y;
	return (true);
}

static bool	try_move_add(t_state *state, t_vector *diff)
{
	return (try_move_add2(state, diff->x, diff->y));
}

void	apply_move(t_state	*state)
{
	t_vector	*ideal_move_diff;

	ideal_move_diff = get_ideal_move_diff(state);
	if (try_move_add(state, ideal_move_diff))
	{
		free(ideal_move_diff);
		return ;
	}
	if (try_move_add2(state, ideal_move_diff->x, 0))
	{
		free(ideal_move_diff);
		return ;
	}
	if (try_move_add2(state, 0, ideal_move_diff->y))
	{
		free(ideal_move_diff);
		return ;
	}
}
