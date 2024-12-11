/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:53:19 by pde-petr          #+#    #+#             */
/*   Updated: 2024/12/11 17:20:52 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%' && !*(format + 1))
		{
			count = -1;
		}
		else if (*format == '%')
			count += ft_printf_format(*(++format), arg);
		else
			count += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(arg);
	return (count);
}

#include <limits.h>
#include <stdio.h>

int	main(void)
{
	// printf(" | ft_pri : %d\n", ft_printf(" NULL %", "dddddd"));
	// printf(" | printf : %d\n", printf(" NULL %", "dddddd"));
	// printf(" | ft_pri : %d\n", ft_printf("s : Hello %s", "World"));
	// printf(" | printf : %d\n", printf("s : Hello %s", "World"));
	// printf(" | ft_pri : %d\n", ft_printf("d : Hello %d", INT_MAX));
	// printf(" | printf : %d\n", printf("d : Hello %d", INT_MAX));
	printf(" | ft_pri : %d\n", ft_printf("i : Hello %i", INT_MAX));
	printf(" | printf : %d\n", printf("i : Hello %i", INT_MAX));
	// printf(" | ft_pri : %d\n", ft_printf("u : Hello %u", INT_MAX));
	// printf(" | printf : %d\n", printf("u : Hello %u", INT_MAX));
	// printf(" | ft_pri : %d\n", ft_printf("x : Hello %x", LONG_MIN));
	// printf(" | printf : %d\n", printf("x : Hello %x", LONG_MIN));
	// printf(" | ft_pri : %d\n", ft_printf("X : Hello %X", INT_MAX));
	// printf(" | printf : %d\n", printf("X : Hello %X", INT_MAX));
	// printf(" | ft_pri : %d\n", ft_printf("p : Hello %p", &ft_printf));
	// printf(" | printf : %d\n", printf("p : Hello %p", &ft_printf));
	// ft_printf(" ft_printf : %d\n", ft_printf(NULL));
	// ft_printf(" printf : %d\n", printf(NULL));
	// printf(" | ft_pri : %d\n", ft_printf("d : Hello %d", INT_MIN));
	// printf(" | printf : %d\n", printf("d : Hello %d", INT_MIN));
	// printf(" | ft_pri : %d\n", ft_printf("i : Hello %i", INT_MIN));
	// printf(" | printf : %d\n", printf("i : Hello %i", INT_MIN));
	// printf(" | ft_pri : %d\n", ft_printf("u : Hello %u", INT_MIN));
	// printf(" | printf : %d\n", printf("u : Hello %u", INT_MIN));
	// printf(" | ft_pri : %d\n", ft_printf("x : Hello %x", INT_MIN));
	// printf(" | printf : %d\n", printf("x : Hello %x", INT_MIN));
	// printf(" | ft_pri : %d\n", ft_printf("X : Hello %X", INT_MIN));
	// printf(" | printf : %d\n", printf("X : Hello %X", INT_MIN));
	return (0);
}
