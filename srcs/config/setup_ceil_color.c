/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ceil_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 21:43:05 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_ceil_part(char **file_text, size_t f, size_t t)
{
	return (f + 1 == t && starts_with(file_text[f], "C "));
}

void	setup_ceil_color(t_state *state, char **file_text, size_t f, size_t t)
{
	char	**splited;
	int		splited_cnt;

	if (state->ceil_color)
		exit_print(CONFIG_ERR_MSG);
	splited = setup_split(file_text[f], ' ', &splited_cnt);
	if (splited_cnt != 2)
		exit_print(CONFIG_ERR_MSG);
	state->ceil_color = str_to_color(splited[1]);
	if (!state->ceil_color)
		exit_print(CONFIG_ERR_MSG);
	free_2d_array(splited);
}
