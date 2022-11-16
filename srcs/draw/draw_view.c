/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:45:34 by kaou              #+#    #+#             */
/*   Updated: 2022/11/16 18:36:15 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_floor_ceil(t_state *state)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y * 2 <= HEIGHT)
				draw_pixel_color(&state->img, x, y, state->ceil_color);
			else
				draw_pixel_color(&state->img, x, y, state->floor_color);
			y++;
		}
		x++;
	}
}

static t_vector	*get_to_column(t_state *state, size_t w)
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

static double	calc_magnification(t_vector *to_cell, t_vector *ray_hit_pos)
{
	return (length(ray_hit_pos) / length(to_cell));
}

static void	set_ray_hits(t_state *state)
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
			state->ray_hits[w + 1]->wall_dir = state->ray_hits[w]->wall_dir;
		}
		w++;
	}
}

static void	draw_raycasting_map(t_state *state)
{
	size_t		w;
	t_vector	*to_cell;
	t_vector	*to_ray_hit;

	set_ray_hits(state);
	w = 0;
	while (w < WIDTH)
	{
		if (w % 20  == 0 && (state->cur_frame % 60 == 0))
			state->debug_ray_hit = 1;
		else
			state->debug_ray_hit = 0;
		to_ray_hit = sub(state->ray_hits[w]->hit_pos, state->player_pos);
		to_cell = get_to_column(state, w);
		draw_column(state, state->ray_hits[w], w, \
			calc_magnification(to_cell, to_ray_hit));
		free(to_cell);
		free_ray_hit(state->ray_hits[w]);
		free(to_ray_hit);
		w++;
	}
}

void	draw_view(t_state *state)
{
	draw_floor_ceil(state);
	draw_raycasting_map(state);
	draw_minimap(state);
	mlx_put_image_to_window(state->mlx, state->win, state->img.img, 0, 0);
}
