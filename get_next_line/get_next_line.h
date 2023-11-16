/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:42:32 by yonieva           #+#    #+#             */
/*   Updated: 2023/11/10 17:43:58 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_save(char *save);
char	*ft_read_save(int fd, char *save);
char	*ft_strchr(char *save, int c);
char	*ft_strdup_line(char *save);
char	*ft_strjoin(char *save, char *buff);
size_t	ft_strlen(char *save);

#endif
