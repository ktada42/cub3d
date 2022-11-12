/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/12 15:36:16 by ktada            ###   ########.fr       */
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

bool	is_blank_line(char **file_text, size_t i)
{
	return (!file_text[i] || !file_text[i][0]);
}

static size_t	setup_config_part(t_state *state, \
	char **file_text, size_t f)
{
	size_t	map_end_line;

	map_end_line = get_next_blank_line(file_text, f);
	if (DEBUG)
		printf("setup config part : f %zu\n", f);
	if (is_no_config(file_text, f, f + 1))
		return (setup_no_texture(state, file_text, f));
	else if (is_so_config(file_text, f, f + 1))
		return (setup_so_texture(state, file_text, f));
	else if (is_we_config(file_text, f, f + 1))
		return (setup_we_texture(state, file_text, f));
	else if (is_ea_config(file_text, f, f + 1))
		return (setup_ea_texture(state, file_text, f));
	else if (is_floor_config(file_text, f, f + 1))
		return (setup_floor_color(state, file_text, f));
	else if (is_ceil_config(file_text, f, f + 1))
		return (setup_ceil_color(state, file_text, f));
	else if (is_map_config(file_text, f, map_end_line))
		return (setup_map(state, file_text, f, map_end_line));
	else
		exit_print("has invalid setting part\n");
	return (-1);
}

//mapは最後
void	setup_config(t_state *state, int argc, char **argv)
{
	char	**file_text;
	size_t	i;

	if (argc != 2)
		exit_print("arg must 2\n");
	check_arg(argc, argv);
	deb("setup_config");
	file_text = get_all_line_without_nl(argv[1]);
	i = 0;
	while (file_text[i])
	{
		if (is_blank_line(file_text, i))
		{
			i++;
			continue ;
		}
		i = setup_config_part(state, file_text, i);
	}
	free_2d_char_array(file_text);
	if (!state->builded_map)
		exit_print("has no map\n");
}
