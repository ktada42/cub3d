/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:23:19 by ktada             #+#    #+#             */
/*   Updated: 2022/11/15 14:19:00 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	is_floor(t_state *state, size_t h, size_t w)
{
	return (\
		(state->map[h][w] == '0' || \
		state->map[h][w] == 'N' || \
		state->map[h][w] == 'S' || \
		state->map[h][w] == 'E' || \
		state->map[h][w] == 'W'));
}

static bool	is_wall(t_state *state, size_t h, size_t w)
{
	return (state->map[h][w] == '1');
}

//左上が(0, 0)
//右下が(WIDTH, HEIGHT)
void	draw_minimap(t_state *state)
{
	size_t		grid_h;
	size_t		grid_w;
	t_grid_pos	*player_pos;

	grid_h = 0;
	while (grid_h < MAP_MAX_HEIGHT)
	{
		grid_w = 0;
		while (grid_w < MAP_MAX_WIDTH)
		{
			if (is_floor(state, grid_h, grid_w))
				minidraw_floor(state, grid_h, grid_w);
			else if (is_wall(state, grid_h, grid_w))
				minidraw_wall(state, grid_h, grid_w);
			grid_w++;
		}
		grid_h++;
	}
	player_pos = get_grid_pos1(state->player_pos);
	minidraw_player(state, player_pos->h, player_pos->w);
	free(player_pos);
}
