/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:02:39 by ktada             #+#    #+#             */
/*   Updated: 2022/11/15 13:46:02 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ft_abs(double v)
{
	if (v < 0)
		v *= -1;
	return (v);
}

double	get_x_by_y_and_rad(double y, double rad)
{
	rad = normalize_rad(rad);
	if (rad == deg_to_rad(90) || \
		rad == deg_to_rad(270) \
	)
	{
		exit_print("get_x_by_y_and_rad \
			rad must not 90 || 270\n");
	}
	return (y / tan(rad));
}

double	get_y_by_x_and_rad(double x, double rad)
{
	rad = normalize_rad(rad);
	if (rad == deg_to_rad(90) || \
		rad == deg_to_rad(270) \
	)
	{
		exit_print("get_y_by_x_and_rad \
			rad must not 90 || 270\n");
	}
	return (x * tan(rad));
}

bool	equal_pos(double a, double b)
{
	return (ft_abs(a - b) < EPS_POS);
}
