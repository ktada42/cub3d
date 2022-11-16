/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:53:04 by ktada             #+#    #+#             */
/*   Updated: 2022/11/16 19:30:43 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_column(t_state *state, t_ray_hit *ray_hit, size_t w, double magnification)
{
	size_t	viewer_wall_height;
	size_t	h;
	t_color	*col;

	viewer_wall_height = (WALL_SIZE / magnification);
	(void)w;
	(void)state;
	(void)ray_hit;
	(void)col;
	h = 0;
	while (h < HEIGHT)
	{
		
		h++;
	}
	/*if (ray_hit->wall_dir[0] == 'n')
			col = make_color(255, 0, 0);
		else if (ray_hit->wall_dir[0] == 'e')
			col = make_color(0, 255, 0);
		else if (ray_hit->wall_dir[0] == 's')
			col = make_color(0, 0, 255);
		else if (ray_hit->wall_dir[0] == 'w')
			col = make_color(0, 255, 255);
		else
			exit_print("color error");
	*/
	if (viewer_wall_height > HEIGHT)
		viewer_wall_height = HEIGHT;
	while (h < viewer_wall_height)
	{
		//draw_pixel_color(&state->img, w, (size_t)(HEIGHT / 2 - (viewer_wall_height / 2.0) + h), col);
		h++;
	}
	//free(col);
}
