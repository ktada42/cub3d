/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:38:50 by kaou              #+#    #+#             */
/*   Updated: 2022/11/12 10:26:17 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*my_malloc(size_t type_size, size_t count)
{
	void	*buf;

	buf = malloc(type_size * count);
	if (!buf)
	{
		perror("malloc");
		exit(1);
	}
	return (buf);
}
