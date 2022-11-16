/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_hit_vertical.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:33:58 by ktada             #+#    #+#             */
/*   Updated: 2022/11/16 19:39:49 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


static bool	angle_almost_vertical(double ray_rad)
{
	return (equal_rad(ray_rad, deg_to_rad(90)) || \
			equal_rad(ray_rad, deg_to_rad(270)));
}

static t_vector	*get_delta(t_vector *first_delta, \
	double ray_rad)
{
	if (first_delta->x != 0)
		return (scalar_mul(first_delta, WALL_SIZE / ft_abs(first_delta->x)));
	else
	{
		if (is_right_dir(ray_rad))
			return (make_vector(\
				WALL_SIZE, get_y_by_x_and_rad(WALL_SIZE, ray_rad)));
		else
			return (make_vector(\
				-WALL_SIZE, get_y_by_x_and_rad(-WALL_SIZE, ray_rad)));
	}
}

static	t_ray_hit	*solve(t_state *state, \
	t_vector *player, double ray_rad, t_vector *first_delta)
{
	t_vector		*delta;
	t_vector		*cur;
	t_ray_hit		*hit;

	delta = get_delta(first_delta, ray_rad);
//	print_vector("player", player);
	cur = add(player, first_delta);
	//print_vector("cur", cur);
	while (!has_wall_at_near(state, cur))
	{
		add_assign(cur, delta);
		//print_vector("add", cur);
	}
	/*if (state->debug_ray_hit)
	{
		print_vector("first_delta", first_delta);
		print_vector("delta", delta);
		print_vector("last cur ", cur);
	}*/
	if (!inside_map(state, cur))
		hit = NULL;
	else
		hit = make_ray_hit(state, cur, false, ray_rad);
	free(delta);
	free(cur);
	return (hit);
}

//
//
//
//下がプラス
static t_vector	*get_first_delta(t_vector *player, double ray_rad)
{
	double	left_dis;
	double	right_dis;

	left_dis = fmod(player->x, WALL_SIZE);
	right_dis = WALL_SIZE - left_dis;
	if (equal_rad(ray_rad, deg_to_rad(0)))
		return (make_vector(right_dis, 0));
	else if (equal_rad(ray_rad, deg_to_rad(180)))
		return (make_vector(-left_dis, 0));
	else if (is_right_dir(ray_rad))
		return (make_vector(right_dis, \
				-get_y_by_x_and_rad(right_dis, ray_rad)));
	else
		return (make_vector(-left_dis, \
				-get_y_by_x_and_rad(-left_dis, ray_rad)));
}

t_ray_hit	*get_ray_hit_vertical(t_state *state, \
	t_vector *player, double ray_rad)
{
	t_vector	*first_delta;
	t_ray_hit	*res;

	/*if (state->debug_ray_hit)
		printf("ray_hit_vertical:\n");*/
	if (angle_almost_vertical(ray_rad))
		return (NULL);
	//todo　最初から縁に立っている時
	first_delta = get_first_delta(player, ray_rad);
	res = solve(state, player, ray_rad, first_delta);
	free(first_delta);
	return (res);
}
