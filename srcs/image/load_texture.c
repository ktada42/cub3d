/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:37:30 by kaou              #+#    #+#             */
/*   Updated: 2022/11/17 16:48:17 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	load_texture(t_state *state, t_img_data *img, char *path)
{
	img->img = mlx_xpm_file_to_image(state->mlx, \
				path, &img->width, &img->height);
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

t_color	*get_pixel_color(t_img_data *img, int x, int y)
{
	size_t	col_i;

	if (!(0 <= x && x < img->width && 0 <= y && y <= img->height))
		return (NULL);
	col_i = (*(unsigned int *)(img->addr + \
			(y * img->line_length + x * (img->bits_per_pixel / 8))));
	return (i_to_col(col_i));
}
