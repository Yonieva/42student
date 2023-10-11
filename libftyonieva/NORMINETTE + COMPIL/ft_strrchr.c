/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:38:56 by yonieva           #+#    #+#             */
/*   Updated: 2023/09/25 22:39:14 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int	i;

	i = 0;
	if (c == 0)
	{
		return (&str[i]);
	}
	while (str[i] != '\0')
	{
		i++;
	}
	while (str[i] != c && i != 0)
	{
		i--;
	}
	if (str[i] == c)
	{
		return (&str[i]);
	}
	else
	{
		return (NULL);
	}
}
