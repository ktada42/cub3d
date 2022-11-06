/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:15:30 by kaou              #+#    #+#             */
/*   Updated: 2022/11/06 20:05:58 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_move_valid(int keycode, t_state *state, bool is_valid)
{
	if (is_left_key(keycode))
		state->press_key_left = is_valid;
	else if (is_up_key(keycode))
		state->press_key_up = is_valid;
	else if (is_right_key(keycode))
		state->press_key_right = is_valid;
	else if (is_down_key(keycode))
		state->press_key_down = is_valid;
	else
	{
		ft_printf("handle keydown code %d is not move\n", keycode);
		exit(1);
	}
}

void	set_turn_valid(int keycode, t_state *state, bool is_valid)
{
	if (keycode == KEY_TURN_L)
		state->press_key_turn_l = is_valid;
	else if (keycode == KEY_TURN_R)
		state->press_key_turn_r = is_valid;
	else
	{
		ft_printf("handle keydown code %d is not turn\n", keycode);
		exit(1);
	}
}

int	handle_key_down(int keycode, t_state *state)
{
	if (DEBUG_KEY)
		ft_printf("key_down : %d \n", keycode);
	if (keycode == KEY_ESC)
		close_all(keycode, state);
	else if (is_move_key(keycode))
		set_move_valid(keycode, state, true);
	else if (is_turn_key(keycode))
		set_turn_valid(keycode, state, true);
	return (0);
}

int	handle_key_up(int keycode, t_state *state)
{
	if (DEBUG_KEY)
		ft_printf("key_up %d \n", keycode);
	if (is_move_key(keycode))
		set_move_valid(keycode, state, false);
	else if (is_turn_key(keycode))
		set_turn_valid(keycode, state, false);
	return (0);
}
