/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:37:30 by kaou              #+#    #+#             */
/*   Updated: 2022/11/12 15:12:05 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	allocate_image(t_state *state)
{
	int	tile_size;

	debug_state_info(state);
	tile_size = WALL_SIZE;
	state->no_wall_texture = mlx_xpm_file_to_image(state->mlx, \
		state->path_no_texture, &tile_size, &tile_size);
	state->ea_wall_texture = mlx_xpm_file_to_image(state->mlx, \
		state->path_ea_texture, &tile_size, &tile_size);
	state->so_wall_texture = mlx_xpm_file_to_image(state->mlx, \
		state->path_so_texture, &tile_size, &tile_size);
	state->we_wall_texture = mlx_xpm_file_to_image(state->mlx, \
		state->path_we_texture, &tile_size, &tile_size);
	if (!state->no_wall_texture || !state->ea_wall_texture || \
		!state->so_wall_texture || !state->we_wall_texture)
		exit_print("wall path error\n");
}
