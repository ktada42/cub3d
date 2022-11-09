/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:53:07 by ktada             #+#    #+#             */
/*   Updated: 2022/11/09 21:56:40 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**setup_split(char **s, char sep, int *cnt)
{
	char	**ret;
	int		len;

	ret = ft_split(s, sep, cnt);
	len = ft_strlen(ret[*cnt - 1]);
	if (ret[len - 1] == '\n')
		ret[len - 1] = '\0';
	return (ret);
}
