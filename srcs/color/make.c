/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:15:16 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 21:17:26 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_color	*make_color(int r, int g, int b)
{
	t_color	*color;

	color = my_malloc(sizeof(t_color), 1);
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}

t_color	*str_to_color(char *str)
{
	char	**rgb;

	rgb = ft_split()
}
