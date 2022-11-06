/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaou <kaou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:25:24 by kaou              #+#    #+#             */
/*   Updated: 2022/04/02 18:44:23 by kaou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen_gnl(src);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (i + 1 < dstsize && i < srclen)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

char	*ft_strjoin_gnl(char *s1, char *s2, t_state_gnl *state)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (ft_strdup_gnl("", state));
	if (!s1)
		return (ft_strdup_gnl(s2, state));
	if (!s2)
		return (ft_strdup_gnl(s1, state));
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
	{
		state->error = true;
		return (NULL);
	}
	ft_strlcpy_gnl(str, s1, s1_len + 1);
	ft_strlcpy_gnl(str + s1_len, s2, s2_len + 1);
	return (str);
}

char	*ft_strdup_gnl(const char *s1, t_state_gnl	*state)
{
	char	*s2;

	s2 = malloc(sizeof(char) * (ft_strlen_gnl(s1) + 1));
	if (!s2)
	{
		state->error = true;
		return (NULL);
	}
	ft_strlcpy_gnl(s2, s1, ft_strlen_gnl(s1) + 1);
	return (s2);
}

char	*ft_substr_gnl(const char *s, \
	size_t start, size_t len, t_state_gnl *state)
{
	char	*str;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen_gnl(s);
	if (len == 0 || slen <= start)
		return (ft_strdup_gnl("", state));
	if (len > slen - start)
		len = slen - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		state->error = true;
		return (NULL);
	}
	ft_strlcpy_gnl(str, s + start, len + 1);
	return (str);
}
