/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:15:16 by ktada             #+#    #+#             */
/*   Updated: 2022/11/17 17:29:16 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_atoi_color(char *s)
{
	int	ret;

	if (*s == '\0')
		return (-1);
	if (starts_with(s, "00"))
		return (-1);
	ret = 0;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (-1);
		ret *= 10;
		ret += *s - '0';
		if (ret > 255)
			return (-1);
		s++;
	}
	return (ret);
}

static	bool	try_parse_color(char *s, int *ret)
{
	*ret = ft_atoi_color(s);
	return (*ret != -1);
}

int	make_color_i(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	str_to_color(char *str)
{
	char	**rgb;
	int		cnt;
	int		ret;
	int		col;

	if (DEBUG)
		printf("{%s}\n", str);
	if (ft_str_cnt(str, ',') != 2)
		return (-1);
	rgb = ft_split(str, ',', &cnt);
	if (cnt != 3)
		return (-1);
	if (!try_parse_color(rgb[0], &(ret)))
		return (-1);
	col = ret << 16;
	if (!try_parse_color(rgb[1], &(ret)))
		return (-1);
	col |= ret << 8;
	if (!try_parse_color(rgb[2], &(ret)))
		return (-1);
	col |= ret;
	free_2d_char_array(rgb);
	return (col);
}
