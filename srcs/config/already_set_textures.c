/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_set_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:42:14 by ktada             #+#    #+#             */
/*   Updated: 2022/11/17 17:50:11 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	already_set_textures(t_state *state)
{
	return (already_set_no(state) && \
			already_set_ea(state) && \
			already_set_so(state) && \
			already_set_we(state) \
	);
}
