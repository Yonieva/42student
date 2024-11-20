/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:37:00 by acabarba          #+#    #+#             */
/*   Updated: 2023/10/19 14:47:43 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nbnoeud;

	nbnoeud = 0;
	while (lst)
	{
		lst = lst->next;
		nbnoeud++;
	}
	return (nbnoeud);
}
