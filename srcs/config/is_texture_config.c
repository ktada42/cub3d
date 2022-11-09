/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_texture_config.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/10 00:47:12 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_no_config(char **file_text, size_t f, size_t t)
{
	return (f + 1 == t && starts_with(file_text[f], "NO "));
}

bool	is_ea_config(char **file_text, size_t f, size_t t)
{
	return (f + 1 == t && starts_with(file_text[f], "EA "));
}

bool	is_so_config(char **file_text, size_t f, size_t t)
{
	return (f + 1 == t && starts_with(file_text[f], "SO "));
}

bool	is_we_config(char **file_text, size_t f, size_t t)
{
	return (f + 1 == t && starts_with(file_text[f], "WE "));
}
