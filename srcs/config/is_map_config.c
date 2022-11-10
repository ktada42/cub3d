/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 22:03:02 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	bool	is_all_of(char *s, char *set)
{
	while (*s)
	{
		if (!ft_strchr(set, *s))
			return (false);
		s++;
	}
	return (true);
}

static bool	is_all_of_2d(char **s, size_t f, size_t t, char	*set)
{
	size_t	i;

	i = f;
	while (i < t)
	{
		if (!is_all_of(s[i], set))
			return (false);
		i++;
	}
	return (true);
}

//スペースだけの行もmapの一部として認める
bool	is_map_config(char **file_text, size_t f, size_t t)
{
	return (is_all_of_2d(file_text, f, t, " 01NESW"));
}
