/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:37:30 by kaou              #+#    #+#             */
/*   Updated: 2022/11/16 22:24:34 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*

	tile_size = WALL_SIZE;
	state->no_wall_texture->img = mlx_xpm_file_to_image(state->mlx, \
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
	if (DEBUG)
		printf("load texture finish\n");

*/

void	load_texture(t_state *state, t_img_data *img, char *path)
{
	img->width = 100;
	img->height = 100;
	img->img = mlx_xpm_file_to_image(state->mlx, path, &img->width, &img->height);
	if (!img->img)
		exit_print("wall path error\n");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
								&img->line_length, &img->endian);
}

//static void	
void	load_textures(t_state *state)
{
	load_texture(state, &state->no_wall_texture, state->path_no_texture);
	load_texture(state, &state->ea_wall_texture, state->path_ea_texture);
	load_texture(state, &state->so_wall_texture, state->path_so_texture);
	load_texture(state, &state->we_wall_texture, state->path_we_texture);
}

size_t	get_pixel_color(t_img_data *img, int x, int y)
{
	unsigned int	*res;

	res = (unsigned int *)img->addr;
	res += (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*res);
}
