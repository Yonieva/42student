/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:49:36 by acabarba          #+#    #+#             */
/*   Updated: 2023/10/30 12:39:54 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	lendigit(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dest;
	size_t	i;

	i = lendigit(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == (NULL))
		return (NULL);
	dest[i] = '\0';
	if (n < 0)
	{
		dest[0] = '-';
		n = n * -1;
	}
	if (n == 0)
		dest[0] = '0';
	while (n != 0)
	{
		dest[--i] = (n % 10) + '0';
		n = n / 10;
	}
	return (dest);
}
