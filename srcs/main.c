/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 21:20:39 by kaou              #+#    #+#             */
/*   Updated: 2022/11/15 23:07:38 by ktada            ###   ########.fr       */
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
	try_apply_move(state);
	draw_view(state);
	/*if (++state->cur_frame % 600 == 0)
	{
		printf("playerpos {%f, %f}\n", state->player_pos->x, state->player_pos->y);
		for (size_t i = 0; i < 360; i+= 1)
		{
			t_ray_hit *hit = get_ray_hit(state, state->player_pos, deg_to_rad((double)i));
			if (hit == NULL)
				printf("ray:deg : %zu, hit{NULL}\n",i);
			else
			{
				printf("ray:deg : %zu, hit{%f, %f} %s\n",i, hit->hit_pos->x, hit->hit_pos->y, hit->wall_dir);

			}
		}
	}*/
	//debug_state_info(state);
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