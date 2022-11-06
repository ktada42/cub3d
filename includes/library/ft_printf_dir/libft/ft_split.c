/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaou <kaou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:25:24 by kaou              #+#    #+#             */
/*   Updated: 2022/04/23 23:57:26 by kaou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_split(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static size_t	ft_find_end(char const *s, size_t cur, char c)
{
	while (s[cur])
	{
		if (s[cur] == c)
			return (cur);
		cur++;
	}
	return (cur);
}

static size_t	ft_find_begin(char const *s, size_t	cur, char c)
{
	while (s[cur])
	{
		if (s[cur] != c)
			return (cur);
		cur++;
	}
	return (cur);
}

static void	ft_set_split(char	**tab, char const *s, char c, size_t	tab_n)
{
	size_t	tab_index;
	size_t	begin;
	size_t	end;

	tab_index = 0;
	begin = ft_find_begin(s, 0, c);
	while (tab_index + 1 < tab_n)
	{
		end = ft_find_end(s, begin, c);
		tab[tab_index] = ft_substr(s, begin, end - begin);
		if (tab[tab_index] == NULL)
		{
			while (tab_index > 0)
			{
				free(tab[tab_index - 1]);
				tab[tab_index-- - 1] = NULL;
			}
			free(tab);
			tab = NULL;
			return ;
		}
		begin = ft_find_begin(s, end, c);
		tab_index++;
	}
	tab[tab_index] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	tab_size;

	if (!s)
		return (NULL);
	tab_size = ft_count_split(s, c) + 1;
	tab = malloc(sizeof(char *) * tab_size);
	if (!tab)
		return (NULL);
	ft_set_split(tab, s, c, tab_size);
	return (tab);
}
