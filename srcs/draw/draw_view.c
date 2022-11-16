/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:45:34 by kaou              #+#    #+#             */
/*   Updated: 2022/11/16 22:24:54 by ktada            ###   ########.fr       */
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

static void	draw_raycasting_map(t_state *state)
{
	size_t		w;
	t_vector	*to_cell;
	t_vector	*to_ray_hit;

	set_ray_hits(state);
	w = 0;
	while (w < WIDTH)
	{
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
	size_t	x = 0;
	printf("image height %d, width %d\n", state->no_wall_texture.height, state->no_wall_texture.width);
	while ( x < (size_t)state->no_wall_texture.height)
	{
		size_t	y = 0;
		while (y < (size_t)state->no_wall_texture.width)
		{
			draw_pixel_i(&(state->img), x, y, get_pixel_color(&state->so_wall_texture, x, y));
			//draw_pixel_i(&(state->img), x, y, 0x00FF0000);
			
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(state->mlx, state->win, state->img.img, 0, 0);
}
