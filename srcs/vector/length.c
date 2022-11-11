/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:08:44 by ktada             #+#    #+#             */
/*   Updated: 2022/11/11 22:54:08 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	length(t_vector	*vec)
{
	return (hypot(vec->x, vec->y));
}

double	distance(t_vector	*lhs, t_vector *rhs)
{
	t_vector	*diff;
	double		dis;

	diff = sub(lhs, rhs);
	dis = length(diff);
	free(diff);
	return (dis);
}
