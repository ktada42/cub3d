/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_set_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:42:14 by ktada             #+#    #+#             */
/*   Updated: 2022/11/17 17:50:11 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	already_set_map(t_state *state)
{
	return (state->builded_map);
}
