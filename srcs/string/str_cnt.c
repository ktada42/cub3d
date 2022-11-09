/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cnt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:16:57 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 22:19:23 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_str_cnt(char *s, char c)
{
	int	ret;

	ret = 0;
	while (*s)
	{
		if (*s == c)
			ret++;
		s++;
	}
	return (ret);
}

int	ft_str_cnt_set(char *s, char *set)
{
	int	ret;

	ret = 0;
	while (*set)
	{
		ret += ft_str_cnt(s, *set);
		set++;
	}
	return (ret);
}

int	ft_str_cnt_set_2d(char **s, size_t f, size_t t, char *set)
{
	int		ret;
	size_t	i;

	i = f;
	ret = 0;
	while (i < t)
	{
		ret += ft_str_cnt_set(s[i], set);
		i++;
	}
	return (ret);
}
