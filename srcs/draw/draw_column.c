/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:53:04 by ktada             #+#    #+#             */
/*   Updated: 2022/11/17 16:51:59 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_color	*get_wall_hit_pixcel(t_ray_hit *ray_hit, \
					size_t h, double magnification)
{
	double	wall_hit_y;
	double	height_center;
	int		texture_hit_x;
	int		texture_hit_y;

	height_center = HEIGHT / 2.0;
	if (h < height_center)
		wall_hit_y = (WALL_SIZE / 2.0) - (PLANE_CELL_SIZE * magnification) \
					* (height_center - h - 0.5f);
	else
		wall_hit_y = (WALL_SIZE / 2.0) + (PLANE_CELL_SIZE * magnification) \
					* (h - height_center + 0.5f);
	texture_hit_x = (int)((double)ray_hit->hit_pos_of_wall / \
					WALL_SIZE * ray_hit->wall_texture->width);
	texture_hit_y = (int)((double)wall_hit_y / \
					WALL_SIZE * ray_hit->wall_texture->height);
	return (get_pixel_color(\
			ray_hit->wall_texture, texture_hit_x, texture_hit_y));
}

void	draw_column(t_state *state, t_ray_hit *ray_hit, \
					size_t w, double magnification)
{
	size_t	h;
	t_color	*col;

	h = 0;
	while (h < HEIGHT)
	{
		col = get_wall_hit_pixcel(ray_hit, h, magnification);
		if (col != NULL)
		{
			draw_pixel_color(&state->img, w, h, col);
			free(col);
		}
		h++;
	}
}
