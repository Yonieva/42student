/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:42:54 by acabarba          #+#    #+#             */
/*   Updated: 2023/11/07 13:13:22 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		nb;
	va_list	args;

	i = 0;
	nb = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			nb += ft_format(args, str[i + 1]);
			i++;
		}
		else
		{
			nb += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (nb);
}
