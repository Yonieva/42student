/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:18:06 by acabarba          #+#    #+#             */
/*   Updated: 2023/10/24 19:44:28 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*j;
	unsigned char	*k;

	i = 0;
	j = (unsigned char *)dest;
	k = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		j[i] = k[i];
		i++;
	}
	dest = j;
	return (j);
}
