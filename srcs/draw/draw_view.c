/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:45:34 by kaou              #+#    #+#             */
/*   Updated: 2022/11/17 17:04:26 by ktada            ###   ########.fr       */
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

long	i1, i2, i3;
int cou = 0;
void	draw_view(t_state *state)
{
	long	t1 = clock();
	draw_floor_ceil(state);
	long	t2 = clock();
	draw_raycasting_map(state);
	long	t3 = clock();
	draw_minimap(state);
	long	t4 = clock();
	i1 += t2 - t1;
	i2 += t3 - t2;
	i3 += t4 - t3;
	cou++;
	if (cou > 100)
	{printf("time sum %ld, %ld, %ld\n", i1, i2, i3);
	exit(1);
	}
	mlx_put_image_to_window(state->mlx, state->win, state->img.img, 0, 0);
}
