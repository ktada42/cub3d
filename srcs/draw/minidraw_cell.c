/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minidraw_cell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 01:11:55 by ktada             #+#    #+#             */
/*   Updated: 2022/11/15 01:20:28 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	minidraw_square(t_state *state, \
						t_grid_pos *pos, size_t size, t_color *col)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			draw_pixel_color(&state->img, pos->w + x, pos->h + y, col);
			y++;
		}
		x++;
	}
}

static void	minidraw_floor(t_state *state, size_t left, size_t top, size_t size)
{
	t_grid_pos	*pos;
	t_color		*col;

	pos = make_grid_pos(top, left);
	col = make_color(255, 255, 255);
	minidraw_square(state, pos, size, col);
	free(pos);
	free(col);
}

static void	minidraw_wall(t_state *state, size_t left, size_t top, size_t size)
{
	t_grid_pos	*pos;
	t_color		*col;

	pos = make_grid_pos(top, left);
	col = make_color(0, 0, 0);
	minidraw_square(state, pos, size, col);
	free(pos);
	free(col);
}

void	minidraw_player(t_state *state, \
							size_t left, size_t top, size_t size)
{
	t_grid_pos	*pos;
	t_color		*col;

	pos = make_grid_pos(top, left);
	col = make_color(255, 0, 0);
	minidraw_square(state, pos, size, col);
	free(pos);
	free(col);
}

void	minidraw_cell(t_state *state, size_t h, size_t w)
{
	size_t	x;
	size_t	y;
	bool	is_floor;

	x = WIDTH - MAP_MAX_WIDTH * MINIMAP_WALL_SIZE - 20;
	y = 20;
	x += w * MINIMAP_WALL_SIZE;
	y += h * MINIMAP_WALL_SIZE;
	is_floor = \
		(state->map[h][w] == '0' || \
		state->map[h][w] == 'N' || \
		state->map[h][w] == 'S' || \
		state->map[h][w] == 'E' || \
		state->map[h][w] == 'W');
	if (is_floor)
		minidraw_floor(state, x, y, MINIMAP_WALL_SIZE);
	else if (state->map[h][w] == '1')
		minidraw_wall(state, x, y, MINIMAP_WALL_SIZE);
}
