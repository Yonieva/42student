/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 02:23:23 by yonieva           #+#    #+#             */
/*   Updated: 2023/09/25 02:23:57 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str2[j] == '\0')
	{
		return (str1);
	}
	while (str1[i] != '\0')
	{
		while (str1[i + j] == str2[j] && str1[i + j] != '\0')
		{
			j++;
		}
		if (str2[j] == '\0')
		{
			return (str1 + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
