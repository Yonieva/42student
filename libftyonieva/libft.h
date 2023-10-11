/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:58:11 by yonieva           #+#    #+#             */
/*   Updated: 2023/10/02 15:52:33 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*---------------------------------AFFICHAGE----------------------------------*/
void	ft_putchar(char c);/*Affiche un caractere*/
void	ft_putstr(char *str);/*Affiche une string*/
void	ft_putnbr(int nb);/*Affiche tout les int* possible dans un write*/
/*----------------------------------------------------------------------------*/

/*--------------------------------CONVERSIONS---------------------------------*/
int		ft_atoi(const char *str);/*Convert char to int in a string*/
/*----------------------------------------------------------------------------*/

/*----------------------TRAITEMENT CHAINE DE CARACTERES-----------------------*/
size_t		ft_strlen(const char *str);/*Return nb char of a string*/
/*----------------------------------------------------------------------------*/

/*---------------------------GESTION DE LA MEMOIRE----------------------------*/
void	*ft_memset(void *blocmem, int c, size_t len);/*remp blc de c, len de x*/
void	ft_bzero(void *blocmem, size_t nb);/*rempli blc de 0, nb de x*/
/*----------------------------------------------------------------------------*/

#endif
