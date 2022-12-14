/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ray_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:33:58 by ktada             #+#    #+#             */
/*   Updated: 2022/11/17 16:16:53 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//todo テストのためにテクスチャネームを代入しているので消す
static	void	set_hit_wall_texture(t_state *state, t_ray_hit *res, \
	bool is_horizontal_query, double ray_rad)
{
	if (is_horizontal_query)
	{
		if (is_up_dir(ray_rad))
			res->wall_texture = &state->no_wall_texture;
		else
			res->wall_texture = &state->so_wall_texture;
	}
	else
	{
		if (is_left_dir(ray_rad))
			res->wall_texture = &state->we_wall_texture;
		else
			res->wall_texture = &state->ea_wall_texture;
	}
}

//壁に接していることが保証される
t_ray_hit	*make_ray_hit(t_state *state, t_vector *hit_pos, \
	bool is_horizontal_query, double ray_rad)
{
	t_ray_hit	*res;

	res = my_malloc(sizeof(t_ray_hit), 1);
	set_hit_wall_texture(state, res, is_horizontal_query, ray_rad);
	res->hit_pos = make_vector(hit_pos->x, hit_pos->y);
	return (res);
}
