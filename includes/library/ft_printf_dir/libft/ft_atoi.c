/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaou <kaou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:25:24 by kaou              #+#    #+#             */
/*   Updated: 2022/03/25 18:56:08 by kaou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char	*str)
{
	int			sign;
	long long	val;

	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	val = 0;
	while (ft_isdigit(*str))
	{
		if (sign * val > LONG_MAX / 10
			|| (sign * val == LONG_MAX / 10 && *str - '0' >= LONG_MAX % 10))
			return ((int)LONG_MAX);
		if (sign * val < LONG_MIN / 10
			|| (sign * val == LONG_MIN / 10 && *str - '0' >= -(LONG_MIN % 10)))
			return ((int)LONG_MIN);
		val = val * 10 + *(str++) - '0';
	}
	return ((int)(sign * val));
}
