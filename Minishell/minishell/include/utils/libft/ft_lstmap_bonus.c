/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:25:34 by acabarba          #+#    #+#             */
/*   Updated: 2023/10/30 13:33:28 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		tmp_lst = ft_lstnew(f(lst->content));
		if (!tmp_lst)
		{
			ft_lstclear(&tmp_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp_lst);
		lst = lst->next;
	}
	return (new_lst);
}
