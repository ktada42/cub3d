/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:33:58 by ktada             #+#    #+#             */
/*   Updated: 2022/11/16 19:40:10 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	void	debug_error_message(t_vector *player, double ray_rad)
{
	ft_printf("player_pos {%f, %f}, ray_rad %f\n", \
				player->x, player->y, ray_rad);
	exit_print("get_ray_hit error(bug) ");
}

//壁のテクスチャや倍率を一緒に返すのもあり
t_ray_hit	*get_ray_hit(t_state *state, t_vector *player, double ray_rad)
{
	t_ray_hit	*horizontal_hit;
	t_ray_hit	*vertical_hit;

	ray_rad = normalize_rad(ray_rad);
	horizontal_hit = get_ray_hit_horizontal(state, player, ray_rad);
	vertical_hit = get_ray_hit_vertical(state, player, ray_rad);
	if (!horizontal_hit && !vertical_hit)
		debug_error_message(player, ray_rad);
	if (!horizontal_hit)
		return (vertical_hit);
	if (!vertical_hit)
		return (horizontal_hit);
	if (ft_abs(distance(player, horizontal_hit->hit_pos) - \
		distance(player, vertical_hit->hit_pos)) < EPS_POS)
		{
		printf("AAAAAAAAAAAAAAA!");
		//state->debug_ray_hit = 1;
		}
	if (distance(player, horizontal_hit->hit_pos) < \
		distance(player, vertical_hit->hit_pos))
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
