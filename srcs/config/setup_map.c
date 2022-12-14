/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/17 17:56:51 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_last_config(t_state *state)
{
	if (!already_set_textures(state))
		exit_print("texture must setting before map\n");
	if (!already_set_color(state))
		exit_print("floor and ceil color must setting before map\n");
	if (already_set_map(state))
		exit_print("map setting duplicate\n");
}

static void	set_start_position(t_state *state, \
	char **file_text, size_t f, size_t t)
{
	t_grid_pos	*start;

	start = my_malloc(sizeof(t_grid_pos), 1);
	set_player_start_position(file_text, f, t, start);
	state->player_pos = cell_top_left(start->h, start->w);
	state->player_pos->x += (double)WALL_SIZE / 2;
	state->player_pos->y += (double)WALL_SIZE / 2;
	free(start);
}

static void	set_start_angle(t_state *state, \
	char **file_text, size_t f, size_t t)
{
	if (ft_str_cnt_set_2d(file_text, f, t, "E"))
		state->player_angle = deg_to_rad(0);
	else if (ft_str_cnt_set_2d(file_text, f, t, "N"))
		state->player_angle = deg_to_rad(90);
	else if (ft_str_cnt_set_2d(file_text, f, t, "W"))
		state->player_angle = deg_to_rad(180);
	else if (ft_str_cnt_set_2d(file_text, f, t, "S"))
		state->player_angle = deg_to_rad(270);
	else
		exit_print("set_start_angle code bug error\n");
}

static void	set_map(t_state *state, char **file_text, size_t f, size_t t)
{
	state->map = make_2d_char_array(MAP_MAX_HEIGHT, MAP_MAX_WIDTH);
	fill(state->map, MAP_MAX_HEIGHT, MAP_MAX_WIDTH, ' ');
	strcpy_2d(state->map, file_text, f, t);
}

size_t	setup_map(t_state *state, char **file_text, size_t f, size_t t)
{
	check_last_config(state);
	check_valid_map(file_text, f, t);
	set_map(state, file_text, f, t);
	set_start_position(state, file_text, f, t);
	set_start_angle(state, file_text, f, t);
	state->builded_map = true;
	return (get_next_blank_line(file_text, f));
}
