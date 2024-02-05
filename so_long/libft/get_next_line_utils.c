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



#include "libft.h"

char	*ft_strchrr(char *save, int c)
{
	int	i;

	i = 0;
	if (!save)
		return (NULL);
	if (c == '\0')
		return ((char *)&save[ft_strlen(save)]);
	while (save[i] != '\0')
	{
		if (save[i] == (char)c)
			return ((char *)&save[i]);
		i++;
	}
	return (0);
}



char	*ft_strdup_line(char *save)
{
	int		i;
	char	*newstr;

	i = 0;
	if (!save[i])
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

char	*ft_strjoinn(char *save, char *buff)
{
	char	*new;
	int		i;
	int		j;

	if (!save)
	{
		save = (char *)malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	if (!save || !buff)
		return (NULL);
	i = -1;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(save) + ft_strlen(buff)) + 1);
	if (!new)
		return (NULL);
	while (save[++i] != '\0')
		new[i] = save[i];
	while (buff[j] != '\0')
		new[i++] = buff[j++];
	new[i] = '\0';
	free(save);
	return (new);
}
