/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktada <ktada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:48:55 by ktada             #+#    #+#             */
/*   Updated: 2022/11/06 20:08:33 by ktada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	*normalize_vector(t_vector *vec)
{
	double	len;

	len = length(vec);
	if (len == 0)
	{
		ft_printf("normalize_vector 0 error\n");
		exit(1);
	}
	return (scalar_div(vec, len));
}
