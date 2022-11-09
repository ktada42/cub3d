/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:49:49 by ktada             #+#    #+#             */
/*   Updated: 2022/11/10 00:41:46 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill(char **dst, size_t height, size_t width, char v)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			dst[i][j] = v;
			j++;
		}
		i++;
	}
}

void	strcpy_2d(char **dst, char **src, size_t f, size_t t)
{
	size_t	i;

	i = f;
	while (i < t)
	{
		ft_strlcpy(dst[i - f], src[i], ft_strlen(dst[i - f]) + 100);
		i++;
	}
}

//copy 2d with wrap as follows
//*******
//*sssss*
//*sssss*
//*sssss*
//*******
void	strcpy_2d_wrap(char **dst, char **src, size_t f, size_t t)
{
	size_t	i;

	i = f;
	while (i < t)
	{
		ft_strlcpy(dst[i - f + 1] + 1, src[i], ft_strlen(dst[i - f]) + 100);
		i++;
	}
}
