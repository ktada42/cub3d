/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_color_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:36:01 by ktada             #+#    #+#             */
/*   Updated: 2022/11/10 00:36:02 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_ceil_config(char **file_text, size_t f, size_t t)
{
	return (f + 1 == t && starts_with(file_text[f], "C "));
}

bool	is_floor_config(char **file_text, size_t f, size_t t)
{
	return (f + 1 == t && starts_with(file_text[f], "F "));
}
