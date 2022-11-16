/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:20:39 by kaou              #+#    #+#             */
/*   Updated: 2022/11/16 21:24:07 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_press_keys(t_state *state)
{
	state->press_key_left = false;
	state->press_key_up = false;
	state->press_key_right = false;
	state->press_key_down = false;
	state->press_key_turn_l = false;
	state->press_key_turn_r = false;
}

static void	set_null_ptr(t_state *state)
{
	state->floor_color = NULL;
	state->ceil_color = NULL;
	state->path_no_texture = NULL;
	state->path_ea_texture = NULL;
	state->path_so_texture = NULL;
	state->path_we_texture = NULL;
	state->player_pos = NULL;
}

void	init_state(t_state *state, int argc, char **argv)
{
	init_press_keys(state);
	set_null_ptr(state);
	state->builded_map = false;
	state->cur_frame = 0;
	setup_config(state, argc, argv);
	print_state(state);
	state->mlx = mlx_init();
	state->win = mlx_new_window(state->mlx, WIDTH, HEIGHT, "cub3d");
	state->img.img = mlx_new_image(state->mlx, WIDTH, HEIGHT);
	state->img.addr = mlx_get_data_addr(state->img.img, \
		&state->img.bits_per_pixel, &state->img.line_length, \
			&state->img.endian);
	load_textures(state);
	mlx_hook(state->win, 17, 1 << 17, close_all, &state);
}
