/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 23:31:34 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	setup_map(t_state *state, char **file_text, size_t f, size_t t)
{
	t_grid_pos	*start;

	if (!state->path_no_texture \
		|| !state->path_ea_texture \
		|| !state->path_so_texture \
		|| !state->path_we_texture \
		|| !state->floor_color \
		|| !state->ceil_color \
		|| !is_valid_map(state, file_text, f, t))
		exit_print(CONFIG_ERR_MSG);
	strcpy_2d(state->map, file_text, f, t);
	start = my_malloc(sizeof(t_grid_pos), 1);
	set_player_position(file_text, f, t, start);
	state->player_pos = 
	free(start);
}
