/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:48:55 by ktada             #+#    #+#             */
/*   Updated: 2022/11/10 23:47:13 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	*add(t_vector *lhs, t_vector *rhs)
{
	return (make_vector(lhs->x + rhs->x, lhs->y + rhs->y));
}

t_vector	*sub(t_vector *lhs, t_vector *rhs)
{
	return (make_vector(lhs->x - rhs->x, lhs->y - rhs->y));
}

t_vector	*scalar_mul(t_vector *lhs, double r)
{
	return (make_vector(lhs->x * r, lhs->y * r));
}

t_vector	*scalar_div(t_vector *lhs, double r)
{
	if (r == 0)
	{
		ft_printf("scalar_div 0 error\n");
		exit(1);
	}
	return (make_vector(lhs->x / r, lhs->y / r));
}

t_vector	*rotate(t_vector *vec, double theta)
{
	return (make_vector(cos(theta) * vec->x - sin(theta) * vec->y, \
						sin(theta) * vec->x + cos(theta) * vec->y));
}
