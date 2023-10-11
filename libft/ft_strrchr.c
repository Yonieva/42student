/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:18:14 by yonieva           #+#    #+#             */
/*   Updated: 2023/10/05 14:18:21 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *)str;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == c)
		{
			j = i;
		}
		i++;
	}
	if (j != 0)
	{
		return (ptr + j);
	}
	else
	{
		return (NULL);
	}
}
