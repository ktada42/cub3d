/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:56:13 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 23:38:20 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	*cell_top_left(size_t h, size_t w)
{
	t_vector	*ret;

	ret = make_vector(h * CELL_SIZE, w * CELL_SIZE);
	return (ret);
}
