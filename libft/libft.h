/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:58:11 by yonieva           #+#    #+#             */
/*   Updated: 2023/10/12 21:44:22 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*--------------------------------AFFICHAGE-----------------------------------*/
void    ft_putchar_fd(char c, int fd);/*affiche char c sur sortie fd*/
void    ft_putstr_fd(char *str, int fd);/*affcihe str sur sortie fd*/
void    ft_putendl_fd(char*str, int fd);/*affiche str + '\n' sur sortie fd*/
/*----------------------------------------------------------------------------*/



/*----------------TRAITEMENT CARACTERES ET CHAINE DE CARACTERES---------------*/
size_t	ft_strlen(const char *str);/*Retourne nb char d une string*/
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);/*cpy src>des*/
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);/*cat src>des*/
int		ft_isalpha(int c);/*Return vrai si 'c' est alpha sinon faux*/
int		ft_isdigit(int c);/*Return vrai si 'c' est numeric sinon faux*/
int		ft_isalnum(int c);/*Return vrai si 'c' est alphanum sinon faux*/
int		ft_isascii(int c);/*Return vrai si 'c' est dans la tabl ascii*/
int		ft_isprint(int c);/*Return vrai si 'c' est imprimable*/
int		ft_tolower(int c);/*Return 'c' en miniscule, sinon return 'c'*/
int		ft_toupper(int c);/*Return 'c' en majuscule, sinon return 'c'*/
int		ft_strncmp(const char *str1, const char *str2, size_t nb);/*Cm*/
char	*ft_strdup(const char *src);/*dup newstring avec malloc*/
char	*ft_strchr(const char *str, int c);/*Pointe 'c' ds str,return suite*/
char	*ft_strrchr(const char *str, int c);/*Pointe derniere occ de c ds str*/
char	*ft_substr(const char *s, unsigned int start, size_t len);/*dup substr*/
char	*ft_strjoin(const char *s1, const char *s2);/*cat s1+s2 ds un newstr*/
char    *ft_strtrim(char const *str, const char *set);/*sup dbt et fin set/str*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/*recherche needle dans haystack len fois et retourne a partir de needle*/
/*----------------------------------------------------------------------------*/



/*---------------------------GESTION DE LA MEMOIRE----------------------------*/
void	ft_bzero(void *blocmem, size_t nb);/*rempli blc de 0, nb de fois*/
void	*ft_calloc(size_t elements, size_t size);/*aloue ele * siz et init a 0*/
void	*ft_memset(void *blocmem, int c, size_t len);/*rempl blc de c, ln de x*/
void	*ft_memchr(const void *str, int c, size_t nb);/*retrn 1e & de c ds str*/
void	*ft_memcpy(void *dest, const void *src, size_t nb);/*cpy src dans dest*/
void	*ft_memmove(void *dest, const void *src, size_t len);/*!chevauchement!*/
int		ft_memcmp(const void *str1, const void *str2, size_t nb);/*cmp 2 bloc*/
/*----------------------------------------------------------------------------*/



/*--------------------------------CONVERSIONS---------------------------------*/
int		ft_atoi(const char *str);/*Convert char en int dans une string*/
/*----------------------------------------------------------------------------*/




#endif
