/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:33:40 by yonieva           #+#    #+#             */
/*   Updated: 2024/02/01 23:33:40 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_item(char *s, char c)
/* retourne le nombre d element collectable sur la map pour verif normes */
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!s)
		return (-1);
	while (s && s[i])
	{
		if (s[i++] == c)
			x++;
	}
	return (x);
}