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

bool	is_up_dir(double ray_rad)
{
	ray_rad = normalize_rad(ray_rad);
	if (ray_rad == 0 || ray_rad == deg_to_rad(180))
	{
		printf("is_up_dir(%f) must not call !!bug!!", ray_rad);
		exit_print("");
	}
	return (ray_rad < deg_to_rad(180));
}

bool	is_down_dir(double ray_rad)
{
	ray_rad = normalize_rad(ray_rad);
	if (ray_rad == 0 || ray_rad == deg_to_rad(180))
	{
		printf("is_down_dir(%f) must not call !!bug!!", ray_rad);
		exit_print("");
	}
	return (ray_rad > deg_to_rad(180));
}

bool	is_left_dir(double ray_rad)
{
	ray_rad = normalize_rad(ray_rad);
	if (ray_rad == deg_to_rad(90) || ray_rad == deg_to_rad(270))
	{
		printf("is_left_dir(%f) must not call !!bug!!", ray_rad);
		exit_print("");
	}
	return (ray_rad < deg_to_rad(90) || ray_rad > deg_to_rad(270));
}

bool	is_right_dir(double ray_rad)
{
	ray_rad = normalize_rad(ray_rad);
	if (ray_rad == deg_to_rad(90) || ray_rad == deg_to_rad(270))
	{
		printf("is_right_dir(%f) must not call !!bug!!", ray_rad);
		exit_print("");
	}
	return (ray_rad > deg_to_rad(90) && ray_rad < deg_to_rad(270));
}
