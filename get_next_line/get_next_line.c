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

#include "get_next_line.h"

char	*ft_read_save(int fd, char *save)
{
	char	*buff;
	int		bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)\
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
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_strdup_line(save);
	save = ft_save(save);
	return (line);
}
/*
int main(void)
{
    int fd;
    char *line;

    // Open a file (replace "example.txt" with the actual file name)
    fd = open("TESTGNL.txt", O_RDONLY);

    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    // Read lines using get_next_line until the end of the file
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Ligne lue : %s\n", line);
        free(line);  // Free the allocated memory for each line
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
*/
