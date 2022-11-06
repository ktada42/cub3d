/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaou <kaou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:25:24 by kaou              #+#    #+#             */
/*   Updated: 2022/01/19 22:36:23 by kaou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_match;

	last_match = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_match = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		last_match = (char *)s;
	return (last_match);
}
