/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:45:34 by kaou              #+#    #+#             */
/*   Updated: 2022/11/09 23:52:56 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_view(t_state *state)
{
	init_canvas(state);
	//todo
	;
	mlx_put_image_to_window(state->mlx, state->win, state->img.img, 0, 0);
}
