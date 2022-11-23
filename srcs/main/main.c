/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:20:39 by kaou              #+#    #+#             */
/*   Updated: 2022/11/23 16:33:01 by ktada            ###   ########.fr       */
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

int	update_frame(t_state	*state)
{
	if (++state->cur_frame % UPDATE_INTERVAL)
		return (0);
	apply_turn(state);
	apply_move(state);
	draw_view(state);
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

/* __attribute__((destructor)) static void destructor()
 {
 	system("leaks -q cub3d");
 }*/