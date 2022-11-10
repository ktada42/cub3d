/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:15:16 by ktada             #+#    #+#             */
/*   Updated: 2022/11/10 23:13:32 by ktada            ###   ########.fr       */
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
	}
	return (ret);
}

static	bool	try_parse_color(char *s, int *ret)
{
	*ret = ft_atoi_color(s);
	return (*ret != -1);
}

t_color	*str_to_color(char *str)
{
	char	**rgb;
	int		cnt;
	t_color	*color;

	if (ft_str_cnt(str, ',') != 2)
		return (NULL);
	color = my_malloc(sizeof(t_color), 1);
	rgb = ft_split(str, ',', &cnt);
	if (cnt != 3)
		return (NULL);
	if (!try_parse_color(rgb[0], &(color->r)))
		return (NULL);
	if (!try_parse_color(rgb[1], &(color->g)))
		return (NULL);
	if (!try_parse_color(rgb[2], &(color->b)))
		return (NULL);
	free_2d_array(rgb);
	return (color);
}
