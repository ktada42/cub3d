/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ea_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 21:09:46 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_ea_part(char **file_text, size_t f, size_t t)
{
	return (f + 1 == t && starts_with(file_text[f], "EA "));
}

void	setup_ea_texture(t_state *state, char **file_text, size_t f, size_t t)
{
	char	**splited;
	int		splited_cnt;

	if (state->path_ea_texture)
		exit_print(CONFIG_ERR_MSG);
	splited = ft_split(file_text[f], ' ', &splited_cnt);
	if (splited_cnt != 2)
		exit_print(CONFIG_ERR_MSG);
	state->path_ea_texture = ft_strdup(splited[1]);
	free_2d_array(splited);
}
