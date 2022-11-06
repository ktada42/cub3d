/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaou <kaou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:31:18 by kaou              #+#    #+#             */
/*   Updated: 2021/11/06 21:08:26 by kaou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (dst < src)
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		else
			*(unsigned char *)(dst + n - 1 - i)
				= *(unsigned char *)(src + n - 1 - i);
		i++;
	}
	return (dst);
}
