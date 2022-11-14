/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:38:24 by ktada             #+#    #+#             */
/*   Updated: 2022/11/14 18:23:35 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_grid_pos	*get_grid_pos2(double x, double y)
{
	return (make_grid_pos((size_t)(y / WALL_SIZE), \
						(size_t)(x / WALL_SIZE)));
}

t_grid_pos	*get_grid_pos1(t_vector *pos)
{
	return (get_grid_pos2(pos->x, pos->y));
}
