/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:33:58 by ktada             #+#    #+#             */
/*   Updated: 2022/11/12 17:44:05 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//壁のテクスチャや倍率を一緒に返すのもあり
t_vector	*get_ray_hit(t_state *state, t_vector *player, double ray_rad)
{
	t_ray_hit	*horizontal_hit;
	t_ray_hit	*vertical_hit;

	horizontal_hit = get_ray_hit_horizontal(state, player, ray_rad);
	vertical_hit = get_ray_hit_vertical(state, player, ray_rad);
	if (!horizontal_hit)
		return (vertical_hit);
	if (!vertical_hit)
		return (horizontal_hit);
	if (distance(player, horizontal_hit->hit_pos) < \
		distance(player, vertical_hit))
	{
		free_ray_hit(vertical_hit);
		return (horizontal_hit);
	}
	else
	{
		free_ray_hit(horizontal_hit);
		return (vertical_hit);
	}
}
