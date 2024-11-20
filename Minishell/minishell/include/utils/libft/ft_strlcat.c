/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:09:16 by acabarba          #+#    #+#             */
/*   Updated: 2023/10/30 12:39:54 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(dest);
	if (count == 0)
		return (ft_strlen(src));
	while (dest[i] && i < count)
		i++;
	while (src[j] && i < count - 1)
		dest[i++] = src[j++];
	if (count != 0 && count >= len)
		dest[i] = '\0';
	if (count < ft_strlen(dest))
		return (ft_strlen(src) + count);
	else
		return (ft_strlen(src) + len);
}
