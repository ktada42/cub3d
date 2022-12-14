/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minidraw_cell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 01:11:55 by ktada             #+#    #+#             */
/*   Updated: 2022/11/17 17:22:31 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	minidraw_square(\
	t_state *state, size_t h, size_t w, int col)
{
	size_t	x;
	size_t	y;
	size_t	left_x;
	size_t	top_y;

	left_x = WIDTH - MAP_MAX_WIDTH * MINIMAP_WALL_SIZE \
			- MINIMAP_OFFSET + w * MINIMAP_WALL_SIZE;
	top_y = MINIMAP_OFFSET + h * MINIMAP_WALL_SIZE;
	x = 0;
	while (x < MINIMAP_WALL_SIZE)
	{
		y = 0;
		while (y < MINIMAP_WALL_SIZE)
		{
			draw_pixel_i(&state->img, left_x + x, top_y + y, \
							col | 0xFF000000);
			y++;
		}
		x++;
	}
}

void	minidraw_floor(t_state *state, size_t h, size_t w)
{
	minidraw_square(state, h, w, make_color_i(255, 255, 255));
}

void	minidraw_wall(t_state *state, size_t h, size_t w)
{
	minidraw_square(state, h, w, make_color_i(0, 0, 0));
}

void	minidraw_player(t_state *state, size_t h, size_t w)
{
	minidraw_square(state, h, w, make_color_i(255, 0, 0));
}
