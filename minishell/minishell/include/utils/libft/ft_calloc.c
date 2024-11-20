/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:07:45 by acabarba          #+#    #+#             */
/*   Updated: 2023/10/27 20:18:17 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointeur;

	if (size != 0 && nmemb * size / size != nmemb)
		return (NULL);
	pointeur = malloc(nmemb * size);
	if (!pointeur)
		return (NULL);
	ft_bzero(pointeur, nmemb * size);
	return (pointeur);
}
