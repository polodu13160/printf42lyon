/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:05:33 by pde-petr          #+#    #+#             */
/*   Updated: 2024/12/03 21:29:11 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned long int hexa, char type)
{
	char	*hexa_tab;

	if (type == 'x')
		hexa_tab = HEXAMIN;
	else
		hexa_tab = HEXACAPS;
	if (hexa < 16)
		return (write(1, &hexa_tab[hexa], 1));
	else
		return (ft_printhexa(hexa / 16, type) + write(1, &hexa_tab[hexa % 16],
				1));
}

static int	check_null_pointer(void *pointer)
{
	if (!pointer)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_printhexa((unsigned long)pointer, 'x'));
}

static int	check_null_string(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (ft_putstr_fd(str, 1));
}

int	ft_printf_format(char format, va_list arg)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	if (format == 's')
		return (check_null_string(va_arg(arg, char *)));
	if (format == 'i' || format == 'd')
		return (ft_putstr_fd(ft_itoa(va_arg(arg, int)), 1));
	if (format == 'x')
		return (ft_printhexa(va_arg(arg, unsigned int), format));
	if (format == 'X')
		return (ft_printhexa(va_arg(arg, unsigned int), format));
	if (format == 'u')
		return (ft_putstr_fd(ft_itoa_unsigned(va_arg(arg, unsigned int)), 1));
	if (format == '%')
		return (write(1, "%", 1));
	if (format == 'p')
		return (check_null_pointer(va_arg(arg, void *)));
	return (write(1, &format, 1));
}