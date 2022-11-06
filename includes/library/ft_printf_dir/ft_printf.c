/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaou <kaou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:29:54 by kaou              #+#    #+#             */
/*   Updated: 2022/03/02 17:08:41 by kaou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsigned(unsigned long n, int base_num, const char	*bases)
{
	int	rtv1;
	int	rtv2;

	rtv1 = 0;
	rtv2 = 0;
	if (n >= (unsigned long)base_num)
		rtv1 = put_unsigned(n / base_num, base_num, bases);
	if (rtv1 < 0)
		return (-1);
	rtv2 = ft_putchar_fd(bases[n % base_num], 1);
	if (rtv2 < 0)
		return (-1);
	return (rtv1 + rtv2);
}

int	put_signed(int n, int base_num, const char *bases)
{
	int	print_cnt;
	int	rtv;

	print_cnt = 0;
	if (n < 0)
	{
		if (ft_putchar_fd('-', 1) < 0)
			return (-1);
		print_cnt++;
		rtv = put_unsigned((unsigned long)((long long)n * -1), base_num, bases);
	}
	else
		rtv = put_unsigned(n, base_num, bases);
	if (rtv < 0)
		return (-1);
	return (print_cnt + rtv);
}

static int	put_address(void	*p, int base_num, const char *bases)
{
	int				rtv1;
	int				rtv2;
	unsigned long	n;

	n = (unsigned long)p;
	rtv1 = ft_putstr_fd("0x", 1);
	if (rtv1 < 0)
		return (-1);
	rtv2 = put_unsigned(n, base_num, bases);
	if (rtv2 < 0)
		return (-1);
	return (rtv1 + rtv2);
}

static int	putchar_specifier(char c, va_list	*ap)
{
	const char	decimal[] = "0123456789";
	const char	hexa_lower[] = "0123456789abcdef";
	const char	hexa_upper[] = "0123456789ABCDEF";

	if (c == 'c')
		return (ft_putchar_fd(va_arg(*ap, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(*ap, char *), 1));
	else if (c == 'p')
		return (put_address(va_arg(*ap, void *), 16, hexa_lower));
	else if (c == 'd' || c == 'i')
		return (put_signed(va_arg(*ap, int), 10, decimal));
	else if (c == 'u')
		return (put_unsigned(va_arg(*ap, unsigned int), 10, decimal));
	else if (c == 'x')
		return (put_unsigned(va_arg(*ap, unsigned int), 16, hexa_lower));
	else if (c == 'X')
		return (put_unsigned(va_arg(*ap, unsigned int), 16, hexa_upper));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	else if (c == '\0')
		return (-1);
	else
		return (ft_putchar_fd(c, 1));
}

int	ft_printf(const	char *format, ...)
{
	va_list	ap;
	int		printed_cnt;
	int		rtv;

	va_start(ap, format);
	printed_cnt = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			rtv = putchar_specifier(*format, &ap);
		}
		else
			rtv = ft_putchar_fd(*format, 1);
		if (rtv < 0)
			return (-1);
		printed_cnt += rtv;
		format++;
	}
	va_end(ap);
	return (printed_cnt);
}
