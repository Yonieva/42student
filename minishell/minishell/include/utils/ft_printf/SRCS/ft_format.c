/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:02:36 by acabarba          #+#    #+#             */
/*   Updated: 2023/11/07 17:17:48 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	nb;

	nb = 0;
	if (format == 'c')
		nb += ft_putchar(va_arg(args, int));
	else if (format == 's')
		nb += ft_putstr(va_arg(args, char *));
	else if (format == 'i')
		nb += ft_putnbr(va_arg(args, int));
	else if (format == 'd')
		nb += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		nb += ft_put_u_nbr(va_arg(args, unsigned int));
	else if (format == 'p')
		nb += ft_put_pointer(va_arg(args, void *));
	else if (format == 'x')
		nb += ft_putnbrhex((long)va_arg(args, unsigned int));
	else if (format == 'X')
		nb += ft_putnbrhe_x((long)va_arg(args, unsigned int));
	else if (format == '%')
		nb += ft_percent();
	return (nb);
}
