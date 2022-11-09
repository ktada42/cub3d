/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_floor_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 21:57:31 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_floor_part(char **file_text, size_t f, size_t t)
{
	return (f + 1 == t && starts_with(file_text[f], "F "));
}

void	setup_floor_color(t_state *state, char **file_text, size_t f, size_t t)
{
	char	**splited;
	int		splited_cnt;

	if (state->floor_color)
		exit_print(CONFIG_ERR_MSG);
	splited = setup_split(file_text[f], ' ', &splited_cnt);
	if (splited_cnt != 2)
		exit_print(CONFIG_ERR_MSG);
	state->floor_color = str_to_color(splited[1]);
	if (!state->floor_color)
		exit_print(CONFIG_ERR_MSG);
	free_2d_array(splited);
}
