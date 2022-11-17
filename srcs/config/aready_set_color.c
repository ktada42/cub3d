/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aready_set_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:37:42 by ktada             #+#    #+#             */
/*   Updated: 2022/11/17 17:54:19 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	already_set_floor(t_state *state)
{
	return (state->floor_color != -1);
}

bool	already_set_ceil(t_state *state)
{
	return (state->ceil_color != -1);
}

bool	already_set_color(t_state *state)
{
	return (already_set_floor(state) && already_set_ceil(state));
}
