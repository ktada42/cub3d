/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:38:50 by kaou              #+#    #+#             */
/*   Updated: 2022/11/11 01:30:04 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*my_malloc(size_t type_size, size_t count)
{
	void	*buf;

	buf = malloc(type_size * count);
	if (!buf)
	{
		//ft_printf("Error\n");
		perror("malloc");
		exit(1);
	}
	return (buf);
}
