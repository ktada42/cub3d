/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_theta.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:45:43 by kaou              #+#    #+#             */
/*   Updated: 2022/11/10 00:07:10 by ktada            ###   ########.fr       */
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
	return (M_PI / 180 * deg);
}
