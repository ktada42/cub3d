/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:37:30 by kaou              #+#    #+#             */
/*   Updated: 2022/11/17 18:01:45 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_vector(char *mes, t_vector *vec)
{
	if (0)
		return ;
	printf("%s", mes);
	printf("{x : %f, y : %f}\n", vec->x, vec->y);
}

void	print_state(t_state *state)
{
	printf("path_ea_texture : %s\n", state->path_ea_texture);
	printf("path_no_texture : %s\n", state->path_no_texture);
	printf("path_so_texture : %s\n", state->path_so_texture);
	printf("path_we_texture : %s\n", state->path_we_texture);
	printf("player_angle : %f\n", state->player_angle);
	print_vector("player_pos", state->player_pos);
	printf("builded_map %d\n", state->builded_map);
	print_map(state->map, MAP_MAX_HEIGHT, MAP_MAX_WIDTH);
}

void	print_map(char	**s, size_t h, size_t w)
{
	size_t	i;	
	size_t	j;	

	if (MAP_MAX_HEIGHT > 30)
		return ;
	i = 0;
	printf("------map---------\n");
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			printf("%c", s[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("------map---------\n");
}

void	deb(char *s)
{
	if (DEBUG)
		printf("debug : %s\n", s);
}
