/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 23:04:15 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_player_position(char **file_text, \
			size_t f, size_t t, t_grid_pos *pos)
{
	int		i;
	int		j;

	i = f;
	while (i < t)
	{
		j = 0;
		while (file_text[i][j])
		{
			if (file_text[i][j] == 'N' || file_text[i][j] == 'E' \
				|| file_text[i][j] == 'S' || file_text[i][j] == 'W')
			{
				pos->h = i;
				pos->w = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

static bool	is_inside(int cur_h, int cur_w, int height, int width)
{
	return (0 <= cur_h && cur_h < height && 0 <= cur_w && cur_w < width);
}

static bool	is_surrounded_wall(char **file_text, size_t size, int cur_h, int cur_w)
{
	bool	ok;

	ok = true;
	file_text[cur_h][cur_w] = '1';
	if (can_move(cur_h + 1, cur_w, size, size))
		ok &= is_surrounded_wall(file_text, size, cur_h + 1, cur_w);
	
}

static bool	player_surrounded_wall(char **file_text, size_t f, size_t t)
{
	t_grid_pos	*start;
	char		buf[MAP_MAX_HEIGHT][MAP_MAX_WIDTH];
	bool		valid;

	my_malloc(sizeof(t_grid_pos), 1);
	set_player_position(file_text, f, t, start);
	fill(buf, MAP_MAX_HEIGHT, MAP_MAX_WIDTH, ' ');
	strcpy_2d(buf, file_text, f, t);
	valid = is_surrounded_wall(file_text, MAP_MAX_HEIGHT, start->h, start->w);
	free(start);
	return (valid);
}

static bool	is_valid_map(t_state *state, char **file_text, size_t f, size_t t)
{
	if (ft_str_cnt_2d(file_text, f, t, "NESW") != 1)
		return (false);
	if (!player_surrounded_wall(file_text, f, t))
		return (false);
	return (true);
}
