/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:56:13 by ktada             #+#    #+#             */
/*   Updated: 2022/11/15 13:45:35 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//if outside return true
bool	has_wall_at_strict(t_state *state, double x, double y)
{
	t_grid_pos	*pos;
	bool		res;

	if (x < 0 || y < 0)
		return (true);
	pos = get_grid_pos2(x, y);
	if (!inside_grid(pos))
		return (true);
	res = (state->map[pos->h][pos->w] == '1');
	free(pos);
	return (res);
}

//if out side map, it's return true
bool	has_wall_at_near(t_state *state, t_vector *pos)
{
	if (pos->x < 0 || pos->y < 0)
		return (true);
	return (\
		has_wall_at_strict(state, pos->x - EPS_POS, pos->y - EPS_POS) || \
		has_wall_at_strict(state, pos->x - EPS_POS, pos->y + EPS_POS) || \
		has_wall_at_strict(state, pos->x + EPS_POS, pos->y - EPS_POS) || \
		has_wall_at_strict(state, pos->x + EPS_POS, pos->y + EPS_POS) \
	);
}

bool	inside_map(t_state *state, t_vector *pos)
{
	t_grid_pos	*grid_pos;
	bool		res;

	(void)state;
	if (pos->x < 0 || pos->y < 0)
		return (false);
	grid_pos = get_grid_pos1(pos);
	res = inside_grid(grid_pos);
	free(grid_pos);
	return (res);
}
