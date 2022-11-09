/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/10 00:13:12 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_is_last_config(t_state *state, char **file_text, size_t f, size_t t)
{
	if (!state->path_no_texture \
		|| !state->path_ea_texture \
		|| !state->path_so_texture \
		|| !state->path_we_texture \
		|| !state->floor_color \
		|| !state->ceil_color)
		exit_print(CONFIG_ERR_MSG);
}

static void	set_start_position(t_state *state, char **file_text, size_t f, size_t t)
{
	t_grid_pos	*start;

	start = my_malloc(sizeof(t_grid_pos), 1);
	set_player_start_position(file_text, f, t, start);
	state->player_pos = cell_top_left(start->h, start->w);
	state->player_pos->x += (double)CELL_SIZE / 2;
	state->player_pos->y += (double)CELL_SIZE / 2;
	free(start);
}

static void	set_start_angle(t_state *state, char **file_text, size_t f, size_t t)
{
	if (ft_str_cnt_set_2d(file_text, f, t, "E"))
		state->player_angle = deg_to_theta(0);
	else if (ft_str_cnt_set_2d(file_text, f, t, "N"))
		state->player_angle = deg_to_theta(90);
	else if (ft_str_cnt_set_2d(file_text, f, t, "W"))
		state->player_angle = deg_to_theta(180);
	else if (ft_str_cnt_set_2d(file_text, f, t, "S"))
		state->player_angle = deg_to_theta(270);
	else
		exit_print("set_start_angle code bug error");
}

void	setup_map(t_state *state, char **file_text, size_t f, size_t t)
{
	check_is_last_config(state, file_text, f, t);
	check_is_valid_map(state, file_text, f, t);
	strcpy_2d(state->map, file_text, f, t);
	set_start_position(state, file_text, f, t);
	set_start_angle(state, file_text, f, t);
}
