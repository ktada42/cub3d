/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ceil_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 21:43:05 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	setup_color(int	*color, char **file_text, size_t f)
{
	char	**splited;
	int		splited_cnt;

	splited = ft_split(file_text[f], ' ', &splited_cnt);
	if (splited_cnt != 2)
		exit_print("color setting arg invalid\n");
	*color = str_to_color(splited[1]);
	if ((*color) == -1)
		exit_print("color setting color code invalid\n");
	free_2d_char_array(splited);
}

size_t	setup_floor_color(t_state *state, char **file_text, size_t f)
{
	if (already_set_floor(state))
		exit_print("floor setting duplicate\n");
	deb("setup_floor_color");
	setup_color(&state->floor_color, file_text, f);
	return (f + 1);
}

size_t	setup_ceil_color(t_state *state, char **file_text, size_t f)
{
	if (already_set_ceil(state))
		exit_print("ceil setting duplicate\n");
	deb("setup_ceil_color");
	setup_color(&state->ceil_color, file_text, f);
	return (f + 1);
}
