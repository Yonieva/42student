/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:50:11 by yonieva           #+#    #+#             */
/*   Updated: 2023/10/16 15:50:17 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	if (nb == 0)
	{
		count++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	int		len;
	int		i;
	char	*result;

	len = int_len(nb);
	i = len - 1;
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	while (nb != 0)
	{
		result[i] = ((nb % 10) + 48);
		nb = nb / 10;
		i--;
	}
	if (nb < 0)
	{
		result[0] = '-';
	}
	result[len] = '\0';
	return (result);
}
