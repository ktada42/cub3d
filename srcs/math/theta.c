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
	while (rad < 0)
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
	return (ft_abs(normalize_rad(rad1) - normalize_rad(rad2)) < EPS_THETA);
}
