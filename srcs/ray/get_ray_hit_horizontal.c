/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_hit_horizontal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:33:58 by ktada             #+#    #+#             */
/*   Updated: 2022/11/11 23:21:34 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	angle_almost_horizontal(double ray_angle)
{
	if (equal_angle(ray_angle, 0) || equal_angle(ray_angle, M_PI))
		return (true);
}

static	t_ray_hit_info	*solve(t_state *state, \
	t_vector *player, double ray_angle, t_vector *first_delta)
{
	
}

//下がプラス
static t_vector	*get_first_delta(t_state *state, \
	t_vector *player, double ray_angle)
{
	double	delta_x;
	double	delta_y;

	if (ray_angle < M_PI)
		delta_y = -fmod(player->y, WALL_SIZE);
	else
		delta_y = WALL_SIZE - fmod(player->y, WALL_SIZE);
	delta_x = delta_y / tan(ray_angle);
	return (make_vector(delta_x, delta_y));
}

t_ray_hit_info	*get_ray_hit_horizontal(t_state *state, \
	t_vector *player, double ray_angle)
{
	t_vector		*first_delta;
	t_ray_hit_info	*res;

	if (angle_almost_horizontal(ray_angle))
		return (NULL);
	first_delta = get_first_delta(state, player, ray_angle);
	res = solve(state, player, ray_angle, first_delta);
	free(first_delta);
	return (res);
}
