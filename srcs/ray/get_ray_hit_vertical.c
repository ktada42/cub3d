/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_hit_vertical.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:33:58 by ktada             #+#    #+#             */
/*   Updated: 2022/11/14 22:29:03 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_ray_hit	*get_ray_hit_vertical(t_state *state, \
	t_vector *player, double ray_rad)
{
	(void)state;
	(void)player;
	(void)ray_rad;
	return (NULL);
	/*
	if (angle_almost_vertical(ray_rad))
		return (NULL);
	first_delta = get_first_delta(player, ray_rad);
	print_vector("first delta ", first_delta);
	res = solve(state, player, ray_rad, first_delta);
	free(first_delta);
	return (res);*/
}
