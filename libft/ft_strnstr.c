/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:37:28 by yonieva           #+#    #+#             */
/*   Updated: 2023/10/10 00:52:34 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (haystack[i] == '\0')
		return (NULL);
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] && needle[j]
			&& i + j < len && haystack[i + j] == needle[j])
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
		j = 0;
	}
	return (NULL);
}
/*
#include <stdio.h>


int	main(void)
{
	const	char *s1 = "This is OOK for now";

	const	char *s2 = "OK";

	printf("Ma fonction pour l exemple 'This is OOK for now', 'OK', et '15'\n");
	printf("%s\n", ft_strnstr(s1, s2, 1));
}
*/
