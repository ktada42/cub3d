/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaou <kaou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:29:54 by kaou              #+#    #+#             */
/*   Updated: 2022/01/21 15:47:44 by kaou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int			put_unsigned(unsigned long n, int base_num, const char	*bases);
int			put_signed(int n, int base_num, const char *bases);
int			ft_printf(const char *format, ...);

#endif
