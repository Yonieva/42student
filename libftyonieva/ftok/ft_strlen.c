/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:52:46 by yonieva           #+#    #+#             */
/*   Updated: 2023/10/02 15:49:06 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
 const char *s1 = "coucou";
 const char *s2 = "enticonstitutionnellement";

 printf("ma fonction %ld, la vrai fonction %ld\n", ft_strlen(s1), strlen(s1));
 printf("ma fonction %ld, la vrai fonction %ld\n", ft_strlen(s2), strlen(s2));

return (0);
}
*/
