/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:45:43 by kaou              #+#    #+#             */
/*   Updated: 2022/11/12 16:47:21 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	normalize_rad(double rad)
{
	while (rad < -M_PI * 2)
		rad += M_PI * 2;
	while (rad > M_PI * 2)
		rad -= M_PI * 2;
	return (rad);
}

double	deg_to_rad(double deg)
{
	return (normalize_rad(M_PI * (deg / 180)));
}

double	rad_to_deg(double rad)
{
	return (180 * (normalize_rad(rad) / M_PI));
}

double	equal_rad(double rad1, double rad2)
{
	return (ft_abs(rad1 - rad2) < EPS_THETA);
}

double	calc_x(double y, double rad)
{
	if (rad == deg_to_rad(90) || \
		rad == deg_to_rad(270) \
	)
	{
		exit_print("calc_x rad must not 90 || 270\n");
	}
	return (y / tan(rad));
}
