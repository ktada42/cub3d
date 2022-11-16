/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:10:30 by ktada             #+#    #+#             */
/*   Updated: 2022/11/16 17:15:39 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	*rotate(t_vector *vec, double rad)
{
	return (make_vector(cos(rad) * vec->x - sin(rad) * vec->y, \
						sin(rad) * vec->x + cos(rad) * vec->y));
}

void	set_rotate(t_vector *vec, double rad)
{
	t_vector	*rotated;

	rotated = rotate(vec, rad);
	copy_vector(vec, rotated);
	free(rotated);
}
