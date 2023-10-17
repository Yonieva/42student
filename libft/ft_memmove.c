/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:44 by yonieva           #+#    #+#             */
/*   Updated: 2023/10/17 18:24:01 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		i;
	char		*bloc1;
	char		*bloc2;

	bloc1 = (char *)dest;
	bloc2 = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (len == 0)
		return (dest);
	if (bloc2 < bloc1)
	{
		i = len;
		while (i > 0)
		{
			i--;
			bloc1[i] = bloc2[i];
		}
	}
	else
	{
		i = 0;
		while (i > len)
		{
			bloc1[i] = bloc2[i];
			i++;
		}
	}
	return (dest);
}
