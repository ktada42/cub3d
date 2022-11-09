/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:45:43 by kaou              #+#    #+#             */
/*   Updated: 2022/11/10 00:17:24 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	normalize_theta(double theta)
{
	while (theta < -M_PI * 2)
		theta += M_PI * 2;
	while (theta > M_PI * 2)
		theta -= M_PI * 2;
	return (theta);
}

double	deg_to_theta(double deg)
{
	return (M_PI * (deg / 180));
}

double	theta_to_deg(double theta)
{
	return (180 * (theta / M_PI));
}
