/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:56:13 by ktada             #+#    #+#             */
/*   Updated: 2022/11/11 22:31:41 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//画面内である前提で呼ばれる
bool	has_wall_at_strict(t_state *state, double x, double y)
{
	return (state-> \
		map[(size_t)(y / WALL_SIZE)][(size_t)(x / WALL_SIZE)] == '1');
}

bool	has_wall_at_near(t_state *state, t_vector *pos)
{
	return (\
		has_wall_at_strict(state, pos->x - EPS, pos->y - EPS) || \
		has_wall_at_strict(state, pos->x - EPS, pos->y + EPS) || \
		has_wall_at_strict(state, pos->x + EPS, pos->y - EPS) || \
		has_wall_at_strict(state, pos->x + EPS, pos->y + EPS) \
	);
}
