/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:42:51 by ktada             #+#    #+#             */
/*   Updated: 2022/11/16 17:25:32 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_vector	*get_moved_pos2(t_state *state, \
		double move_horizontal, double move_vertical)
{
	t_vector	*x_vec;
	t_vector	*y_vec;
	t_vector	*moved_pos;

	x_vec = make_vector(0, -1);
	y_vec = make_vector(1, 0);
	set_rotate(x_vec, state->player_angle);
	set_rotate(y_vec, state->player_angle);
	scalar_mul_assign(x_vec, move_horizontal);
	scalar_mul_assign(y_vec, -move_vertical);
	moved_pos = add(x_vec, y_vec);
	moved_pos->y *= -1;
	add_assign(moved_pos, state->player_pos);
	free(x_vec);
	free(y_vec);
	return (moved_pos);
}

//todo
static t_vector	*get_moved_pos(t_state *state)
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
	return (get_moved_pos2(state, move_horizontal, move_vertical));
}

void	try_apply_move(t_state	*state)
{
	t_vector	*moved_pos;

	moved_pos = get_moved_pos(state);
	if (!has_wall_at_near(state, moved_pos))
		copy_vector(state->player_pos, moved_pos);
	free(moved_pos);
}
