/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:38:24 by ktada             #+#    #+#             */
/*   Updated: 2022/11/14 17:41:23 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_grid_pos	*make_grid_pos(int h, int w)
{
	t_grid_pos	*pos;

	pos = my_malloc(sizeof(t_grid_pos), 1);
	pos->h = h;
	pos->w = w;
	return (pos);
}
