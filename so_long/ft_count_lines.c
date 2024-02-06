/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:08:44 by yonieva           #+#    #+#             */
/*   Updated: 2024/02/01 23:08:44 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	exit_error(void)
{
	ft_printf("Erreur\nmauvaise dimension de la map\n");
	exit(EXIT_FAILURE);
}

int	ft_count_lines(int fd, int x, int img_w)
/* return le nombre de ligne du fichier map pour verif normes*/
{
	char	*line;
	int		linecount;

	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_printf("x: %d, img_w: %d, line: %s\n", x, img_w, line);
		size_t line_length = ft_strlen(line);
		if ((int)line_length < (x / img_w) || (line_length == 1 && *line != '\n'))
		{
			ft_printf("Expected Length: %d, Actual Length: %d\n", x / img_w, line_length);
			free(line);
			exit_error();
		}
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}