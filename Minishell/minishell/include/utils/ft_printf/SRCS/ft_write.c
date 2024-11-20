/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:07:08 by acabarba          #+#    #+#             */
/*   Updated: 2023/11/08 22:45:59 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long long int n)
{
	int	i;

	i = ft_intlen(n);
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (i);
}

int	ft_put_u_nbr(unsigned int n)
{
	int	i;

	i = ft_intlen(n);
	if (n <= 9)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_put_u_nbr(n / 10);
		ft_put_u_nbr(n % 10);
	}
	return (i);
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}
