/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:17:04 by yonieva           #+#    #+#             */
/*   Updated: 2023/11/10 19:38:46 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_save(int fd, char *save)
{
	char	*buff;
	int		bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(save, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			free(save);
			return (NULL);
		}
		buff[bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (NULL);
	i++;
	while (save[i] != '\0')
		s[j++] = save[i++];
	s[j] = '\0';
	free(save);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[4096];

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = ft_read_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_strdup_line(save[fd]);
	save[fd] = ft_save(save[fd]);
	return (line);
}
/*
int main(void)
{
    int fd1, fd2, fd3;
    char *line;

    // Open two files for reading
    fd1 = open("1.txt", O_RDONLY);
    fd2 = open("2.txt", O_RDONLY);
	fd3 = open("3.txt", O_RDONLY);

    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
    {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("File 1 Line: %s\n", line);
        free(line);
    }

    while ((line = get_next_line(fd2)) != NULL)
    {
        printf("File 2 Line: %s\n", line);
        free(line);
    }

	while ((line = get_next_line(fd3)) != NULL)
	{
		printf("File 3 Line: %s\n", line);
		free(line);
	}

    // Close the file descriptors
    close(fd1);
    close(fd2);
	close(fd3);

    return 0;
}
*/