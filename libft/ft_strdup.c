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
	char	*srcdup;
	size_t	i;
	size_t	j;

	i = ft_strlen(src + 1);
	j = 0;
	srcdup = (char *)src;
	newstr = (char *)malloc(sizeof(char) * i);
	if (newstr == NULL)
	{
		return (NULL);
	}
	while (srcdup[j] != '\0')
	{
		newstr[j] = srcdup[j];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}
