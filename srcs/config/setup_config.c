/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/17 16:00:24 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
