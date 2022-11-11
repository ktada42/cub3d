/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:56:13 by ktada             #+#    #+#             */
/*   Updated: 2022/11/11 22:26:05 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	*cell_top_left(size_t h, size_t w)
{
	t_vector	*ret;

	ret = make_vector(w * WALL_SIZE, h * WALL_SIZE);
	return (ret);
}
