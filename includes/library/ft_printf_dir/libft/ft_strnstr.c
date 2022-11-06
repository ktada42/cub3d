/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaou <kaou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:25:24 by kaou              #+#    #+#             */
/*   Updated: 2021/10/22 16:03:14 by kaou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;
	char	*str;

	i = 0;
	str = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return (str);
	while (str[i] && i + needle_len - 1 < len)
	{
		if (ft_strncmp(str + i, needle, needle_len) == 0)
			return (str + i);
		i++;
	}
	return (NULL);
}
