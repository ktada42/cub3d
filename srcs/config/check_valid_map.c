/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/12 13:21:22 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_player_start_position(char **file_text, \
			size_t f, size_t t, t_grid_pos *pos)
{
	size_t	i;
	size_t	j;

	i = f;
	while (i < t)
	{
		j = 0;
		while (file_text[i][j])
		{
			if (file_text[i][j] == 'N' || file_text[i][j] == 'E' \
				|| file_text[i][j] == 'S' || file_text[i][j] == 'W')
			{
				pos->h = i - f;
				pos->w = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

//if player surrounded wall, it's ok case
//1111
//11N01
//  11110000
//  00000000
//
//
// 111
// 1N1
// 111
static bool	is_surrounded_wall(char **map, int cur_h, int cur_w)
{
	if (map[cur_h][cur_w] == ' ' || map[cur_h][cur_w] == '\0')
		return (false);
	map[cur_h][cur_w] = '1';
	if (map[cur_h + 1][cur_w] != '1' \
		&& !is_surrounded_wall(map, cur_h + 1, cur_w))
		return (false);
	if (map[cur_h][cur_w + 1] != '1' \
		&& !is_surrounded_wall(map, cur_h, cur_w + 1))
		return (false);
	if (map[cur_h - 1][cur_w] != '1' \
		&& !is_surrounded_wall(map, cur_h - 1, cur_w))
		return (false);
	if (map[cur_h][cur_w - 1] != '1' \
		&& !is_surrounded_wall(map, cur_h, cur_w - 1))
		return (false);
	return (true);
}

static bool	player_surrounded_wall(char **file_text, size_t f, size_t t)
{
	t_grid_pos	*start;
	char		**buf;
	bool		valid;

	start = my_malloc(sizeof(t_grid_pos), 1);
	buf = make_2d_char_array(MAP_MAX_HEIGHT + 2, MAP_MAX_WIDTH + 2);
	set_player_start_position(file_text, f, t, start);
	fill(buf, MAP_MAX_HEIGHT + 2, MAP_MAX_WIDTH + 2, ' ');
	strcpy_2d_wrap(buf, file_text, f, t);
	deb("buf");
	print_map(buf, MAP_MAX_HEIGHT + 2, MAP_MAX_WIDTH + 2);
	valid = is_surrounded_wall(buf, start->h + 1, start->w + 1);
	free(start);
	free_2d_char_array(buf);
	return (valid);
}

bool	has_only_one_player(char **file_text, size_t f, size_t t)
{
	return (ft_str_cnt_set_2d(file_text, f, t, "NESW") == 1);
}

void	check_valid_map(char **file_text, size_t f, size_t t)
{
	if (is_too_big_map(file_text, f, t))
		exit_print("too big map\n");
	if (!has_only_one_player(file_text, f, t))
		exit_print("has not only one player\n");
	if (!player_surrounded_wall(file_text, f, t))
		exit_print("player not surrounded wall\n");
}
