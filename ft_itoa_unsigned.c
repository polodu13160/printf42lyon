/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:39:21 by pde-petr          #+#    #+#             */
/*   Updated: 2024/12/03 22:51:45 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_unsigned(unsigned int nb)
{
	unsigned int	buffer;
	int				i;
	char			*malloc_str;

	i = 1;
	buffer = nb;
	while (buffer >= 10)
	{
		buffer /= 10;
		i++;
	}
	malloc_str = ft_calloc(i + 1, sizeof(char));
	if (!malloc_str)
		return (NULL);
	while (i > 0)
	{
		malloc_str[--i] = (nb % 10) + 48;
		nb = (nb / 10);
	}
	return (malloc_str);
}
