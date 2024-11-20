/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:16:13 by acabarba          #+#    #+#             */
/*   Updated: 2023/11/07 17:17:48 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbrhex(unsigned long n)
{
	char	*tab;
	int		i;

	i = 0;
	tab = "0123456789abcdef";
	if (n < 16)
		i += ft_putchar(tab[n]);
	else
	{
		i += ft_putnbrhex(n / 16);
		i += ft_putchar(tab[n % 16]);
	}
	return (i);
}

int	ft_putnbrhe_x(unsigned long n)
{
	char	*tab;
	int		i;

	i = 0;
	tab = "0123456789ABCDEF";
	if (n < 16)
		i += ft_putchar(tab[n]);
	else
	{
		i += ft_putnbrhe_x(n / 16);
		i += ft_putchar(tab[n % 16]);
	}
	return (i);
}
