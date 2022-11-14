/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:23:19 by ktada             #+#    #+#             */
/*   Updated: 2022/11/15 00:31:44 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//左上が(0, 0)
//右下が(WIDTH, HEIGHT)
void	draw_minimap(t_state *state)
{
	(void)state;
	int	h = -20;
	while (h < 21)
	{
		int w = -20;
		while (w < 21)
		{
			t_color	*color;
			color = make_color(255, 0, 0);
			draw_pixel_color(&state->img, WIDTH / 2 + h, HEIGHT / 2 + w, color);
			free(color);
			w ++;
		}
		h++;
	}
	//todo;
}
