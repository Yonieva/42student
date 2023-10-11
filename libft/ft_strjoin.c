/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:17:53 by yonieva           #+#    #+#             */
/*   Updated: 2023/10/11 14:18:58 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*newstring;
	int				i;
	int				j;
	size_t			len;

	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	i = 0;
	j = 0;
	newstring = (char *)malloc(sizeof(char) * len);
	if (newstring == NULL)
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
/*
int main()
{
    const char *chaine1 = "Hello, ";
    const char *chaine2 = "world!";

    char *resultat = ft_strjoin(chaine1, chaine2);
    printf("Résultat de ma fonction : %s\n", resultat);

    free(resultat);

    return 0;
}
*/
