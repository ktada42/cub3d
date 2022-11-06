/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaou <kaou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:53:58 by kaou              #+#    #+#             */
/*   Updated: 2022/06/16 16:54:15 by kaou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include"../ft_printf_dir/ft_printf.h"
#include <fcntl.h>

void	*my_malloc_gnl(size_t type_size, size_t count)
{
	void	*buf;

	buf = malloc(type_size * count);
	if (!buf)
	{
		ft_printf("MallocError\n");
		exit(1);
	}
	return (buf);
}

void	append_string(char	***ret, char	*add, int *i, int *size)
{
	char	**ret2;
	int		j;

	if (*i >= *size)
	{
		*size *= 2;
		ret2 = my_malloc_gnl(sizeof(char *), *size + 1);
		j = -1;
		while (++j < *size + 1)
			ret2[j] = NULL;
		j = -1;
		while (++j < *i)
		{
			ret2[j] = ft_strdup((*ret)[j]);
			free((*ret)[j]);
		}
		free(*ret);
		*ret = ret2;
	}
	(*ret)[*i] = ft_strdup(add);
	(*i)++;
}

//中身がi行の時、ret[i] == NULLになる(i以降もNULL)
char	**get_file_text(char *file_path)
{
	char	**ret;
	int		i;
	int		fd;
	char	*line;
	int		size;

	i = 0;
	size = 1;
	ret = my_malloc_gnl(sizeof(char *), size + 1);
	ret[0] = NULL;
	ret[1] = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		free(ret);
		return (NULL);
	}
	line = get_next_line(fd);
	while (line)
	{
		append_string(&ret, line, &i, &size);
		free(line);
		line = get_next_line(fd);
	}
	return (ret);
}
