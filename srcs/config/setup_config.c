/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 20:53:36 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F 220,100,0
C 225,30,0

1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
*/

static	bool	is_blank_line(char **file_text, size_t i)
{
	return (!file_text[i] || file_text[i][0] == '\n');
}

void	setup_config_part(t_state *state, char **file_text, size_t f, size_t t)
{
	if (is_no_part(file_text, f, t))
		setup_no_texture(state, file_text, f, t);
	else if (is_so_part(file_text, f, t))
		setup_so_texture(state, file_text, f, t);
	else if (is_we_part(file_text, f, t))
		setup_we_texture(state, file_text, f, t);
	else if (is_ea_part(file_text, f, t))
		setup_ea_texture(state, file_text, f, t);
	else if (is_floor_part(file_text, f, t))
		setup_floor_texture(state, file_text, f, t);
	else if (is_ceil_part(file_text, f, t))
		setup_ceil_texture(state, file_text, f, t);
	else if (is_map_part(file_text, f, t))
		setup_map_texture(state, file_text, f, t);
	else
		exit_print(CONFIG_ERR_MSG);
}

//現状ファイルの中身はmapしかない想定(テクスチャや色の設定は受け取らない)
//mapは最後
void	setup_config(t_state *state, int argc, char **argv)
{
	char	**file_text;
	size_t	i;
	size_t	j;

	if (argc != 2)
		exit_print("arg must 2\n");
	file_text = get_file_text(argv[1]);
	i = 0;
	while (file_text[i])
	{
		if (is_blank_line(file_text, i))
			continue ;
		j = i;
		while (!is_blank_line(file_text, j))
			j++;
		setup_config_part(state, file_text, i, j);
		i = j;
	}
	free_2d_array(file_text);
}