/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <acabarba@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:30:25 by acabarba          #+#    #+#             */
/*   Updated: 2024/07/08 16:30:25 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
/*			get_next_line		*/
char	*get_next_line(int fd);
char	*gnl_ad_to_stash(int fd, char *s);
char	*gnl_line(char *stash);
char	*gnl_clean_static(char *stash);
/*			get_next_line_utils	*/
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *c);
void	gnl_bzero(void *s, size_t n);
void	*gnl_calloc(size_t nmemb, size_t size);
char	*gnl_strjoin(char *s1, char *s2);

#endif