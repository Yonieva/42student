/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:42:41 by yonieva           #+#    #+#             */
/*   Updated: 2023/11/10 19:47:21 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)c)
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_line(char *save)
{
	int		i;
	char	*newstr;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	newstr = (char *)malloc(sizeof(char) * (i + 2));
	if (!newstr)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		newstr[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		newstr[i] = save[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	int		i;
	int		j;
	size_t	len;

	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	i = 0;
	j = 0;
	newstring = (char *)malloc(sizeof(char) * len);
	if (!newstring)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstring[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		newstring[i] = s2[j];
		j++;
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
