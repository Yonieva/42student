/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:54:46 by yonieva           #+#    #+#             */
/*   Updated: 2024/03/07 21:33:52 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *ptr;
	int temp;
	ptr = lst;

	while (lst->next != NULL)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = ptr;
		}
		else
		{
			lst = lst->next;
		}
	}
	lst = ptr;
	return (lst);


	
}