/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/17 17:36:02 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	setup_texture(char **path_ptr, char **file_text, size_t f)
{
	char	**splited;
	int		splited_cnt;

	if (*path_ptr)
	{
		//printf("line:%zu path == %s\n", f, *path_ptr);
		exit_print("duplicate texture setting\n");
	}
	splited = ft_split(file_text[f], ' ', &splited_cnt);
	if (splited_cnt != 2)
		exit_print("text setting arg invalid\n");
	*path_ptr = ft_strdup(splited[1]);
	free_2d_char_array(splited);
}

size_t	setup_no_texture(t_state *state, char **file_text, size_t f)
{
	deb("setup_no");
	setup_texture(&state->path_no_texture, file_text, f);
	return (f + 1);
}

size_t	setup_so_texture(t_state *state, char **file_text, size_t f)
{
	deb("setup_so");
	setup_texture(&state->path_so_texture, file_text, f);
	return (f + 1);
}

size_t	setup_ea_texture(t_state *state, char **file_text, size_t f)
{
	deb("setup_ea");
	setup_texture(&state->path_ea_texture, file_text, f);
	return (f + 1);
}

size_t	setup_we_texture(t_state *state, char **file_text, size_t f)
{
	deb("setup_we");
	setup_texture(&state->path_we_texture, file_text, f);
	return (f + 1);
}
