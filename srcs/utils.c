/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:33:23 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 22:16:48 by ktada            ###   ########.fr       */
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

void	free_2d_array(char **ar)
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
