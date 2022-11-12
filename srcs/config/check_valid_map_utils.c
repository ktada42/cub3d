/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:34 by ktada             #+#    #+#             */
/*   Updated: 2022/11/12 12:30:29 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_too_big_map(char **file_text, size_t f, size_t t)
{
	size_t	i;

	if (t - f > MAP_MAX_HEIGHT)
		return (true);
	i = f;
	while (i < t)
	{
		if (ft_strlen(file_text[i]) > MAP_MAX_WIDTH)
			return (true);
		i++;
	}
	return (false);
}

void	check_arg(int argc, char **argv)
{
	char	*suffix;

	(void)argc;
	suffix = ft_strrchr(argv[1], '.');
	if (!suffix || ft_strncmp(suffix, ".cub", 5)
		|| !ft_strncmp((suffix - 1), "/.cub", 6))
		exit_print("invalid file name\n");
	else if (ft_strlen(argv[1]) == 4)
		exit_print("invalid file name\n");
}
