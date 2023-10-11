/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:44 by yonieva           #+#    #+#             */
/*   Updated: 2023/10/03 16:07:16 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*bloc1;
	const unsigned char	*bloc2;

	i = 0;
	bloc1 = (unsigned char *)dest;
	bloc2 = (unsigned char *)src;
	if (bloc2 < bloc1)
	{
		while (i <= len)
		{
			bloc1[len - i] = bloc2[len - i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			bloc1[i] = bloc2[i];
			i++;
			len--;
		}
	}
	return (dest);
}
