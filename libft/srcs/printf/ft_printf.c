/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clados-s <clados-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:21:12 by clados-s          #+#    #+#             */
/*   Updated: 2025/08/06 09:59:39 by clados-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char format, va_list args)
{
	unsigned long	ptr_val;

	if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == 'p')
	{
		ptr_val = va_arg(args, unsigned long);
		if (ptr_val == 0)
			return (ft_putstr("(nil)"));
		return (ft_putstr("0x") + ft_puthexa(ptr_val, "0123456789abcdef"));
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			count += check_format(*s, args);
		}
		else
			count += write(1, s, 1);
		s++;
	}
	va_end(args);
	return (count);
}
