/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_assign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:04:55 by ktada             #+#    #+#             */
/*   Updated: 2022/11/12 17:14:16 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	add_assign(t_vector *lhs, t_vector *rhs)
{
	t_vector	*res;

	res = (make_vector(lhs->x + rhs->x, lhs->y + rhs->y));
	copy_vector(lhs, res);
	free(res);
}

void	sub_assign(t_vector *lhs, t_vector *rhs)
{
	t_vector	*res;

	res = (make_vector(lhs->x - rhs->x, lhs->y - rhs->y));
	copy_vector(lhs, res);
	free(res);
}

void	scalar_mul_assign(t_vector *lhs, double r)
{
	t_vector	*res;

	res = (make_vector(lhs->x * r, lhs->y * r));
	copy_vector(lhs, res);
	free(res);
}

void	scalar_div_assign(t_vector *lhs, double r)
{
	t_vector	*res;

	if (r == 0)
	{
		ft_printf("scalar_div 0 error\n");
		exit(1);
	}
	res = make_vector(lhs->x / r, lhs->y / r);
	copy_vector(lhs, res);
	free(res);
}
