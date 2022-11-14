/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:23:19 by ktada             #+#    #+#             */
/*   Updated: 2022/11/15 01:20:53 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
			minidraw_cell(state, grid_h, grid_w);
			grid_w++;
		}
		grid_h++;
	}
	player_pos = get_grid_pos1(state->player_pos);

	size_t size = MINIMAP_WALL_SIZE;
	size_t x = WIDTH - MAP_MAX_WIDTH * size - 20;
	size_t y = 20;
	x += player_pos->w * size;
	y += player_pos->h * size;
	minidraw_player(state, x, y, size);
}
