/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:15:16 by ktada             #+#    #+#             */
/*   Updated: 2022/11/11 20:18:42 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_color	*i_to_col(int color_int)
{
	t_color	*ret;

	ret = my_malloc(sizeof(t_color), 1);
	ret->b = (color_int >> 0) & 0xFF;
	ret->g = (color_int >> 8) & 0xFF;
	ret->r = (color_int >> 16) & 0xFF;
	return (ret);
}

int	make_color_i(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	col_to_i(t_color *col)
{
	return (col->r << 16 | col->g << 8 | col->b);
}
