/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:43:07 by ktada             #+#    #+#             */
/*   Updated: 2022/11/17 16:19:30 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	*get_to_column(t_state *state, size_t w)
{
	double		plane_dis;
	t_vector	*to_plane;
	t_vector	*to_column;
	t_vector	*res;

	plane_dis = get_x_by_y_and_rad(\
		((double)PLANE_CELL_SIZE * WIDTH) / 2, deg_to_rad(FOV_DEG / 2.0));
	to_plane = make_vector(plane_dis, 0);
	to_column = make_vector(to_plane->x, \
		((double)PLANE_CELL_SIZE * WIDTH) / 2 - \
		PLANE_CELL_SIZE * w - (PLANE_CELL_SIZE / 2.0));
	res = rotate(to_column, state->player_angle);
	free(to_plane);
	free(to_column);
	res->y *= -1;
	return (res);
}

double	calc_magnification(t_vector *to_cell, t_vector *ray_hit_pos)
{
	return (length(ray_hit_pos) / length(to_cell));
}

static void	erase_noise(t_state *state)
{
	size_t	w;

	w = 0;
	while (w + 2 < WIDTH)
	{
		if (state->ray_hits[w]->wall_texture != \
			state->ray_hits[w + 1]->wall_texture && \
			state->ray_hits[w]->wall_texture == \
			state->ray_hits[w + 2]->wall_texture \
		)
		{
			state->ray_hits[w + 1]->wall_texture = \
				state->ray_hits[w]->wall_texture;
		}
		w++;
	}
}

static void	set_hit_wall_pos(t_state *state)
{
	size_t		w;
	t_ray_hit	*ray_hit;

	w = 0;
	while (w < WIDTH)
	{
		ray_hit = state->ray_hits[w];
		if (ray_hit->wall_texture == &state->no_wall_texture)
			ray_hit->hit_pos_of_wall = fmod(ray_hit->hit_pos->x, WALL_SIZE);
		else if (ray_hit->wall_texture == &state->ea_wall_texture)
			ray_hit->hit_pos_of_wall = fmod(ray_hit->hit_pos->y, WALL_SIZE);
		else if (ray_hit->wall_texture == &state->so_wall_texture)
			ray_hit->hit_pos_of_wall = fmod(WALL_SIZE - \
				fmod(ray_hit->hit_pos->x, WALL_SIZE), WALL_SIZE);
		else if (ray_hit->wall_texture == &state->we_wall_texture)
			ray_hit->hit_pos_of_wall = fmod(WALL_SIZE - \
				fmod(ray_hit->hit_pos->y, WALL_SIZE), WALL_SIZE);
		w++;
	}
}

void	set_ray_hits(t_state *state)
{
	size_t		w;
	t_vector	*to_cell;

	w = 0;
	while (w < WIDTH)
	{
		to_cell = get_to_column(state, w);
		state->ray_hits[w] = get_ray_hit(state, state->player_pos, \
								atan2(-to_cell->y, to_cell->x));
		free(to_cell);
		w++;
	}
	erase_noise(state);
	set_hit_wall_pos(state);
}
