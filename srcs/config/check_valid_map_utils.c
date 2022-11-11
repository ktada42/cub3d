/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/11 19:20:47 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_too_big_map(char **file_text, size_t f, size_t t)
{
	size_t	i;

	if (t - f > MAP_MAX_HEIGHT)
		return (true);
	i = f;
	while (i < t)
	{
		if (ft_strlen(file_text[i]) > MAP_MAX_WIDTH)
			return (true);
		i++;
	}
	return (false);
}
