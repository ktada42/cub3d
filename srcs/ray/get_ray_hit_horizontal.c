/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_hit_horizontal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:33:58 by ktada             #+#    #+#             */
/*   Updated: 2022/11/12 20:43:48 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	angle_almost_horizontal(double ray_rad)
{
	return (equal_rad(ray_rad, 0) || equal_rad(ray_rad, M_PI));
}

static	t_ray_hit	*solve(t_state *state, \
	t_vector *player, double ray_rad, t_vector *first_delta)
{
	t_vector		*delta;
	t_vector		*cur;

	delta = scalar_mul(first_delta, WALL_SIZE / first_delta->y);
	cur = add(player, first_delta);
	while (!has_wall_at_near(state, cur))
	{
		add_assign(cur, delta);
	}
	return (make_ray_hit(state, cur, true, ray_rad));
}

//
//
//
//下がプラス
static t_vector	*get_first_delta(t_state *state, \
	t_vector *player, double ray_rad)
{
	double	top_dis;
	double	down_dis;

	top_dis = fmod(player->y, WALL_SIZE);
	down_dis = WALL_SIZE - top_dis;
	if (equal_rad(ray_rad, deg_to_rad(90)))
		return (make_vector(0, -top_dis));
	else if (equal_rad(ray_rad, deg_to_rad(270)))
		return (make_vector(0, down_dis));
	else if (ray_rad < deg_to_rad(180))
		return (make_vector(calc_x(top_dis, ray_rad), -top_dis));
	else
		return (make_vector(calc_x(-down_dis, ray_rad), down_dis));
}

t_ray_hit	*get_ray_hit_horizontal(t_state *state, \
	t_vector *player, double ray_rad)
{
	t_vector	*first_delta;
	t_ray_hit	*res;

	if (angle_almost_horizontal(ray_rad))
		return (NULL);
	//todo　最初から縁に立っている時
	first_delta = get_first_delta(state, player, ray_rad);
	res = solve(state, player, ray_rad, first_delta);
	free(first_delta);
	return (res);
}
