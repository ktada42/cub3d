/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:38:24 by ktada             #+#    #+#             */
/*   Updated: 2022/11/14 23:49:06 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	inside_grid(t_grid_pos *grid_pos)
{
	return (0 <= grid_pos->h && grid_pos->h < MAP_MAX_HEIGHT && \
			0 <= grid_pos->w && grid_pos->w < MAP_MAX_WIDTH);
}
