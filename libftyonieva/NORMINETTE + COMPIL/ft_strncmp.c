/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:49:53 by yonieva           #+#    #+#             */
/*   Updated: 2023/09/24 22:53:15 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *str1, char *str2, unsigned int nb)
{
	unsigned int	i;

	i = 0;
	if (nb == 0)
	{
		return (0);
	}
	while (str1[i] && str2[i] && i < nb - 1 && str1[i] == str2[i])
	{
		i++;
	}
	return ((str1[i] - str2[i]));
}
