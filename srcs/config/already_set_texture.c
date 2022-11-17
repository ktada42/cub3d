/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_set_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:42:14 by ktada             #+#    #+#             */
/*   Updated: 2022/11/17 17:50:11 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	already_set_no(t_state *state)
{
	return (state->path_no_texture);
}

bool	already_set_ea(t_state *state)
{
	return (state->path_ea_texture);
}

bool	already_set_so(t_state *state)
{
	return (state->path_so_texture);
}

bool	already_set_we(t_state *state)
{
	return (state->path_we_texture);
}
