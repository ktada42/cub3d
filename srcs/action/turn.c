/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:42:51 by ktada             #+#    #+#             */
/*   Updated: 2022/11/10 00:07:33 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	apply_turn(t_state	*state)
{
	if (state->press_key_turn_l)
		state->player_angle -= TURN_RATE;
	if (state->press_key_turn_r)
		state->player_angle += TURN_RATE;
	state->player_angle = normalize_theta(state->player_angle);
}
