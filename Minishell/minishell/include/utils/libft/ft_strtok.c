/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <kpourcel@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:35:42 by kpourcel          #+#    #+#             */
/*   Updated: 2024/10/15 18:57:20 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *delim, char **saveptr)
{
	char	*start;
	char	*token;

	if (str)
		*saveptr = str;
	if (!*saveptr)
		return (NULL);
	start = *saveptr + ft_strspn(*saveptr, delim);
	if (*start == '\0')
	{
		*saveptr = NULL;
		return (NULL);
	}
	token = start;
	*saveptr = ft_strpbrk(start, delim);
	if (*saveptr)
		*(*saveptr)++ = '\0';
	return (token);
}
