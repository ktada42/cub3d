/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:48:55 by ktada             #+#    #+#             */
/*   Updated: 2022/11/06 20:02:48 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	*make_vector(double x, double y)
{
	t_vector	*vec;

	vec = my_malloc(sizeof(t_vector), 1);
	return (vec);
}

void	copy_vector(t_vector *dst, t_vector *src)
{
	dst->x = src->x;
	dst->y = src->y;
}
