/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_move_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:37:30 by kaou              #+#    #+#             */
/*   Updated: 2022/11/10 01:01:06 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_left_key(int keycode)
{
	return (keycode == KEY_A);
}

bool	is_up_key(int keycode)
{
	return (keycode == KEY_W);
}

bool	is_right_key(int keycode)
{
	return (keycode == KEY_D);
}

bool	is_down_key(int keycode)
{
	return (keycode == KEY_S);
}

bool	is_move_key(int keycode)
{
	return (is_left_key(keycode) || \
			is_up_key(keycode) || \
			is_right_key(keycode) || \
			is_down_key(keycode) \
	);
}
