/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:37:30 by kaou              #+#    #+#             */
/*   Updated: 2022/11/11 02:16:54 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_color(char *mes, t_color	*color)
{
	printf(mes);
	printf(" : ");
	printf("r %s, ", color->r);
	printf("g %s, ", color->g);
	printf("b %s, \n", color->b);
}

void	print_state(t_state *state)
{
	print_color("floor color", state->floor_color);
	print_color("ceil color", state->ceil_color);
	printf("path_ea_texture : %s\n", state->path_ea_texture);
	printf("path_no_texture : %s\n", state->path_no_texture);
	printf("path_so_texture : %s\n", state->path_so_texture);
	printf("path_we_texture : %s\n", state->path_we_texture);
	printf("start_player_dir : %c\n", state->start_player_dir);
	printf("player_angle : %f\n", state->player_angle);
	print_vector("player_pos");
}
