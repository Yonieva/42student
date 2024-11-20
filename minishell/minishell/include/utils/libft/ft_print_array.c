/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:31:49 by acabarba          #+#    #+#             */
/*   Updated: 2024/07/30 12:05:45 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * Fonction pour afficher le tableau de char
 */
void	ft_print_array(char **array)
{
	int	i;

	if (array == NULL)
	{
		printf("Aucun argument à afficher.\n");
		return ;
	}
	i = 0;
	while (array[i])
	{
		printf("Argument %d: %s\n", i, array[i]);
		i++;
	}
}
