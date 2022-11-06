/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaou <kaou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:31:31 by kaou              #+#    #+#             */
/*   Updated: 2021/10/24 21:38:01 by kaou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n)
{
	size_t	cou;

	if (n == 0)
		return (1);
	cou = 0;
	if (n < 0)
		cou++;
	while (n)
	{
		n /= 10;
		cou++;
	}
	return (cou);
}

static long long	ft_abs(int n)
{
	if (n < 0)
		return ((long long)n * -1);
	return (n);
}	

char	*ft_itoa(int n)
{
	char		*buf;
	size_t		buf_size;
	size_t		i;
	long long	abs_n;

	buf_size = count_digits(n) + 1;
	buf = malloc(sizeof(char) * buf_size);
	if (!buf)
		return (NULL);
	if (n < 0)
		buf[0] = '-';
	buf[buf_size - 1] = '\0';
	if (n == 0)
	{
		buf[0] = '0';
		return (buf);
	}
	i = buf_size - 2;
	abs_n = ft_abs(n);
	while (abs_n)
	{
		buf[i--] = '0' + abs_n % 10;
		abs_n /= 10;
	}
	return (buf);
}
