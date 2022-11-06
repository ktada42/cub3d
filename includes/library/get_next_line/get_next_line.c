/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaou <kaou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:53:58 by kaou              #+#    #+#             */
/*   Updated: 2022/06/13 17:30:05 by kaou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	*free_null_gnl(char	**p1, char	**p2)
{
	if (p1 != NULL)
	{
		free(*p1);
		*p1 = NULL;
	}
	if (p2 != NULL)
	{
		free(*p2);
		*p2 = NULL;
	}
	return (NULL);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	else
		return (NULL);
}

char	*cut_line(char	**memo, t_state_gnl	*state)
{
	size_t	cut_pos;
	char	*head;
	char	*tail;

	if (!memo || !(*memo))
		return (NULL);
	if (!(**memo))
		return (free_null_gnl(memo, NULL));
	if (state->exist_lf)
		cut_pos = ft_strchr_gnl(*memo, '\n') - *memo + 1;
	else
		cut_pos = ft_strchr_gnl(*memo, '\0') - *memo;
	head = ft_substr_gnl(*memo, 0, cut_pos, state);
	if (state->error)
		return (free_null_gnl(memo, NULL));
	tail = ft_substr_gnl(*memo, cut_pos, ft_strlen_gnl(*memo) - cut_pos, state);
	if (state->error)
		return (free_null_gnl(memo, &head));
	free_null_gnl(memo, NULL);
	*memo = tail;
	return (head);
}

char	*ft_read_fd(int fd, t_state_gnl	*state)
{
	char	*buf;
	ssize_t	read_cnt;

	buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
	{
		state->error = true;
		return (NULL);
	}
	read_cnt = read(fd, buf, BUFFER_SIZE);
	if (read_cnt < 0)
	{
		state->error = true;
		return (free_null_gnl(&buf, NULL));
	}
	else if (read_cnt == 0)
		state->eof = true;
	buf[read_cnt] = '\0';
	if (ft_strchr_gnl(buf, '\n'))
		state->exist_lf = true;
	return (buf);
}

char	*get_next_line(int fd)
{
	static char		*memo_fds[256];
	char			*buf;
	char			*joined_buf;
	t_state_gnl		state;

	if (fd < 0 || fd >= 256 || BUFFER_SIZE <= 0)
		return (NULL);
	state.eof = false;
	state.error = false;
	state.exist_lf = ft_strchr_gnl(memo_fds[fd], '\n') != NULL;
	while (!state.eof && !state.exist_lf)
	{
		buf = ft_read_fd(fd, &state);
		if (state.error)
			return (free_null_gnl(memo_fds + fd, NULL));
		joined_buf = ft_strjoin_gnl(memo_fds[fd], buf, &state);
		if (state.error)
			return (free_null_gnl(memo_fds + fd, &buf));
		free_null_gnl(memo_fds + fd, &buf);
		memo_fds[fd] = joined_buf;
	}
	return (cut_line(memo_fds + fd, &state));
}
