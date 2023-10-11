/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:33:21 by yonieva           #+#    #+#             */
/*   Updated: 2023/10/10 00:53:36 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s8;

	s8 = (char *)malloc(sizeof(*s) * (len + 1));
	if (!s8 || start > ft_strlen(s))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			s8[j] = s[i];
			j++;
		}
		i++;
	}
	s8[j] = 0;
	return (s8);
}
