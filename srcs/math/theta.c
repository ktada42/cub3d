/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:45:43 by kaou              #+#    #+#             */
/*   Updated: 2022/11/11 23:04:26 by ktada            ###   ########.fr       */
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
	return (normalize_theta(M_PI * (deg / 180)));
}

double	theta_to_deg(double theta)
{
	return (180 * (normalize_theta(theta) / M_PI));
}

double	equal_theta(double theta1, double theta2)
{
	return (ft_abs(theta1 - theta2) < EPS_THETA);
}
