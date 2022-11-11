/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:45:34 by kaou              #+#    #+#             */
/*   Updated: 2022/11/11 22:32:46 by ktada            ###   ########.fr       */
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

void	draw_view(t_state *state)
{
	draw_floor_ceil(state);
	mlx_put_image_to_window(state->mlx, state->win, state->img.img, 0, 0);
}
