/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:41:42 by yonieva           #+#    #+#             */
/*   Updated: 2023/10/05 14:42:02 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
	{
		return (0);
	}
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < nb)
	{
		i++;
	}
	return (str1[i] - str2[i]);
}
