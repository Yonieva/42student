/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:44:28 by acabarba          #+#    #+#             */
/*   Updated: 2023/10/31 16:17:06 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *str, char sep)
{
	unsigned int	i;
	unsigned int	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] != sep && str[i + 1] == sep)
		{
			nbr++;
			i++;
		}
		if (str[i] != sep && str[i + 1] == '\0')
		{
			nbr++;
			i++;
		}
		else
			i++;
	}
	return (nbr);
}

static char	**create_tab(char *str, char sep, char **dest)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		j = i;
		while (str[i] && str[i] != sep)
			i++;
		if (i > j)
		{
			dest[k] = malloc(sizeof(char) * (i - j + 1));
			if (!dest[k])
				return (NULL);
			ft_strlcpy(dest[k++], &str[j], i - j + 1);
			dest[k] = NULL;
		}
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		nbword;

	nbword = count_word((char *)s, c);
	dest = (char **)malloc(sizeof(char *) * (nbword + 1));
	if (!dest)
		return (NULL);
	dest = create_tab((char *)s, c, dest);
	dest[nbword] = (NULL);
	return (dest);
}
