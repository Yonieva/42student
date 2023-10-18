/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:33:00 by yonieva           #+#    #+#             */
/*   Updated: 2023/10/06 14:03:05 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*newstr;
	size_t	len;

	len = ft_strlen(src) + 1;
	newstr = (char *)malloc(len * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, src, len);
	return (newstr);
}
