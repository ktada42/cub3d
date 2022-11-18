/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_hit_horizontal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:33:58 by ktada             #+#    #+#             */
/*   Updated: 2022/11/18 21:39:19 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	angle_almost_horizontal(double ray_rad)
{
	return (equal_rad(ray_rad, 0) || equal_rad(ray_rad, M_PI));
}

static t_vector	*get_delta(t_vector *first_delta, \
	double ray_rad)
{
	if (first_delta->y != 0)
		return (scalar_mul(first_delta, WALL_SIZE / ft_abs(first_delta->y)));
	else
	{
		if (normalize_rad(ray_rad) == deg_to_rad(90))
			return (make_vector(0, -WALL_SIZE));
		else if (normalize_rad(ray_rad) == deg_to_rad(270))
			return (make_vector(0, WALL_SIZE));
		else if (is_up_dir(ray_rad))
			return (make_vector(\
				get_x_by_y_and_rad(WALL_SIZE, ray_rad), -WALL_SIZE));
		else
			return (make_vector(\
				get_x_by_y_and_rad(-WALL_SIZE, ray_rad), WALL_SIZE));
	}
}

static	t_ray_hit	*solve(t_state *state, \
	t_vector *player, double ray_rad, t_vector *first_delta)
{
	t_vector		*delta;
	t_vector		*cur;
	t_ray_hit		*hit;

	delta = get_delta(first_delta, ray_rad);
	cur = add(player, first_delta);
	while (!has_wall_at_near(state, cur))
	{
		add_assign(cur, delta);
	}
	if (!inside_map(state, cur))
		hit = NULL;
	else
		hit = make_ray_hit(state, cur, true, ray_rad);
	free(delta);
	free(cur);
	return (hit);
}

//下がプラス
static t_vector	*get_first_delta(t_vector *player, double ray_rad)
{
	double	top_dis;
	double	down_dis;

	top_dis = fmod(player->y, WALL_SIZE);
	down_dis = WALL_SIZE - top_dis;
	if (equal_rad(ray_rad, deg_to_rad(90)))
		return (make_vector(0, -top_dis));
	else if (equal_rad(ray_rad, deg_to_rad(270)))
		return (make_vector(0, down_dis));
	else if (is_up_dir(ray_rad))
		return (make_vector(get_x_by_y_and_rad(top_dis, ray_rad), -top_dis));
	else
		return (make_vector(get_x_by_y_and_rad(-down_dis, ray_rad), down_dis));
}

t_ray_hit	*get_ray_hit_horizontal(t_state *state, \
	t_vector *player, double ray_rad)
{
	t_vector	*first_delta;
	t_ray_hit	*res;

	if (angle_almost_horizontal(ray_rad))
		return (NULL);
	first_delta = get_first_delta(player, ray_rad);
	res = solve(state, player, ray_rad, first_delta);
	free(first_delta);
	return (res);
}
