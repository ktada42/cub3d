/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/10 23:42:07 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	setup_texture(char **path_ptr, char **file_text, size_t f, size_t t)
{
	char	**splited;
	int		splited_cnt;

	if (*path_ptr)
		exit_print(CONFIG_ERR_MSG);
	splited = ft_split(file_text[f], ' ', &splited_cnt);
	if (splited_cnt != 2)
		exit_print(CONFIG_ERR_MSG);
	*path_ptr = ft_strdup(splited[1]);
	free_2d_array(splited);
}

void	setup_no_texture(t_state *state, char **file_text, size_t f, size_t t)
{
	setup_texture(&state->path_no_texture, file_text, f, t);
}

void	setup_so_texture(t_state *state, char **file_text, size_t f, size_t t)
{
	setup_texture(&state->path_so_texture, file_text, f, t);
}

void	setup_ea_texture(t_state *state, char **file_text, size_t f, size_t t)
{
	setup_texture(&state->path_ea_texture, file_text, f, t);
}

void	setup_we_texture(t_state *state, char **file_text, size_t f, size_t t)
{
	setup_texture(&state->path_we_texture, file_text, f, t);
}
