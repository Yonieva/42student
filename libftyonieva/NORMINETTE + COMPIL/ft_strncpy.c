/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:54:00 by yonieva           #+#    #+#             */
/*   Updated: 2023/09/24 14:54:09 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Copie les nb premiers caracteres de src dans dest
*/

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, int nb)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
