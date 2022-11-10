/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:33:23 by ktada             #+#    #+#             */
/*   Updated: 2022/11/11 01:30:10 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_print(char *mes)
{
	ft_printf(mes);
	exit(1);
}

bool	starts_with(char *str, char *prefix)
{
	while (*prefix)
	{
		if (*str != *prefix)
			return (false);
		str++;
		prefix++;
	}
	return (true);
}


char	**make_2d_char_array(int h, int w)
{
	char	**ret;
	int		i;

	ret = my_malloc(sizeof(char *), h);
	i = 0;
	while (i < h)
	{
		ret[i] = my_malloc(sizeof(char), w);
		i++;
	}
	return (ret);
}

void	free_2d_char_array(char **ar)
{
	size_t	h;

	h = 0;
	while (ar[h])
	{
		free(ar[h]);
		h++;
	}
	free(ar);
}
