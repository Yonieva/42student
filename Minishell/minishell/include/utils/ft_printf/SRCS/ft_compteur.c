/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compteur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:33:55 by acabarba          #+#    #+#             */
/*   Updated: 2023/11/07 17:19:55 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_intlen(long long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	i++;
	return (i);
}

int	ft_put_pointer(void *n)
{
	int	i;

	i = 0;
	if (n == NULL)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	else
	{
		i += ft_putstr("0x");
		i += ft_putnbrhex((unsigned long)n);
		return (i);
	}
}
