/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:42:51 by ktada             #+#    #+#             */
/*   Updated: 2022/11/12 10:09:29 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	*get_moved_pos(t_state *state)
{
	t_vector	*moved_pos;

	moved_pos = make_vector(state->player_pos->x, state->player_pos->y);
	if (state->press_key_left)
		moved_pos->x -= MOVE_RATE;
	if (state->press_key_up)
		moved_pos->y -= MOVE_RATE;
	if (state->press_key_right)
		moved_pos->x += MOVE_RATE;
	if (state->press_key_down)
		moved_pos->y += MOVE_RATE;
	return (moved_pos);
}

void	try_apply_move(t_state	*state)
{
	t_vector	*moved_pos;

	moved_pos = get_moved_pos(state);
	if (!has_wall_at_near(state, moved_pos))
		copy_vector(state->player_pos, moved_pos);
	free(moved_pos);
}
