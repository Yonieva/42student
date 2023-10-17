/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:55:15 by yonieva           #+#    #+#             */
/*   Updated: 2023/10/16 17:17:42 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;

	if (destsize <= ft_strlen(dest))
		return (destsize + ft_strlen(src));
	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0' && i + 1 < destsize)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}

/*
#include <stdio.h>

int main ()
{
	char	*str123;
	char	*str234;

	str1 = "Salut";
	str2 = "Ca va ?";
	printf("Ma fonction : %ld\n", ft_strlcat(str234, str123, 5));
	printf("La fonction strlcat : %ld\n", strlcat(str234, str123, 5));
}
*/
