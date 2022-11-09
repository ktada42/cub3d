/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_canvas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:09:38 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 23:51:00 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_canvas(t_state *state)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			draw_pixel(&(state->img), x, y, \
				get_bg_color_left_up0(state, x, y));
		}
	}
}
