/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:37:30 by kaou              #+#    #+#             */
/*   Updated: 2022/11/12 15:35:19 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	allocate_image(t_state *state)
{
	int	tile_size;

	printf("no {%s}\n", state->path_no_texture);
	printf("ea {%s}\n", state->path_ea_texture);
	printf("so {%s}\n", state->path_so_texture);
	printf("we {%s}\n", state->path_we_texture);
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
