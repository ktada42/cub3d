/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:54:34 by kaou              #+#    #+#             */
/*   Updated: 2022/11/09 23:43:53 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# define BUFFER_SIZE 300

typedef struct s_file_state_gnl
{
	bool	eof;
	bool	error;
	bool	exist_lf;
}	t_state_gnl;

size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2, t_state_gnl *state);
char	*ft_strdup_gnl(const char *s1, t_state_gnl	*state);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(const char *s, size_t left, size_t len, t_state_gnl *st);
char	*get_next_line(int fd);
char	**get_all_line(char *file_path);

#endif
