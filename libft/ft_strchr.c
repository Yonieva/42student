/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:39:40 by yonieva           #+#    #+#             */
/*   Updated: 2023/11/14 14:50:40 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*str1;

	i = 0;
	str1 = (char *)str;
	while (str1[i] != '\0' || (char)c == '\0')
	{
		if (str1[i] == (char)c)
			return (str1 + i);
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int	main ()
{
	const char *str = "Comment?";
	int	c = 'm';

	printf("Ma fonction pour l exemple 'Comment?' : %s\n", ft_strchr(str, c));
	printf("La fonction strchr : %s\n", strchr(str, c));
}
*/
