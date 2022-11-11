/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_ray_hits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:33:58 by ktada             #+#    #+#             */
/*   Updated: 2022/11/11 22:56:53 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


t_ray_hit_info	*get_ray_hit_horizontal(t_state *state, \
	t_vector *player, double ray_angle)
{
	if (angle_almost_horizontal)
	return (NULL);
}
//壁のテクスチャや倍率を一緒に返すのもあり
t_vector	*get_ray_hit(t_state *state, t_vector *player, double ray_angle)
{
	t_ray_hit_info	*horizontal_hit;
	t_ray_hit_info	*vertical_hit;

	horizontal_hit = get_ray_hit_horizontal(state, player, ray_angle);
	vertical_hit = get_ray_hit_vertical(state, player, ray_angle);
	if (!horizontal_hit)
		return (vertical_hit);
	if (!vertical_hit)
		return (horizontal_hit);
	if (distance(player, horizontal_hit->hit_pos) < \
		distance(player, vertical_hit))
	{
		free_ray_hit_info(vertical_hit);
		return (horizontal_hit);
	}
	else
	{
		free_ray_hit_info(horizontal_hit);
		return (vertical_hit);
	}
}
