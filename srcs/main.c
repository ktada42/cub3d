/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:20:39 by kaou              #+#    #+#             */
/*   Updated: 2022/11/09 21:04:50 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_all(int keycode, t_state *state)
{
	(void)keycode;
	(void)state;
	exit(0);
	return (0);
}

void	init_press_keys(t_state *state)
{
	state->press_key_left = false;
	state->press_key_up = false;
	state->press_key_right = false;
	state->press_key_down = false;
	state->press_key_turn_l = false;
	state->press_key_turn_r = false;
	state->cur_frame = 0;
}

void	init_state(t_state *state, int argc, char **argv)
{
	state->mlx = mlx_init();
	state->win = mlx_new_window(state->mlx, WIDTH, HEIGHT, "cub3d");
	state->img.img = mlx_new_image(state->mlx, WIDTH, HEIGHT);
	state->img.addr = mlx_get_data_addr(state->img.img, \
		&state->img.bits_per_pixel, &state->img.line_length, \
			&state->img.endian);
	mlx_hook(state->win, 17, 1 << 17, close_all, &state);
	init_press_keys(state);
	state->player_pos = make_vector(0, 0);//todo
	setup_config(state, argc, argv);
}

int	update_frame(t_state	*state)
{
	if (++state->cur_frame % UPDATE_INTERVAL)
		return (0);
	apply_turn(state);
	try_apply_move(state);
	draw_map(state);
	debug_state_info(state);
	return (0);
}

int	main(int argc, char **argv)
{
	t_state		state;

	init_state(&state, argc, argv);
	mlx_hook(state.win, ON_KEYDOWN, 1L << 0, handle_key_down, &state);
	mlx_hook(state.win, ON_KEYUP, 1L << 1, handle_key_up, &state);
	mlx_loop_hook(state.mlx, update_frame, &state);
	mlx_loop(state.mlx);
	return (0);
}
/*
__attribute__((destructor)) static void destructor()
{
	system("leaks -q cub3d");
}
*/