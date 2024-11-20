/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acabarba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:44:23 by acabarba          #+#    #+#             */
/*   Updated: 2023/11/07 17:13:32 by acabarba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
/*		MAIN			*/
int		ft_printf(const char *str, ...);
int		ft_format(va_list args, const char format);
/*		WRITE			*/
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long long int n);
int		ft_put_u_nbr(unsigned int n);
int		ft_percent(void);
/*		puthex			*/
int		ft_putnbrhex(unsigned long n);
int		ft_putnbrhe_x(unsigned long n);
/*		TRANSFORM		*/
int		ft_atoi(const char *str);
/*		COMPTEUR		*/
int		ft_intlen(long long nb);
int		ft_put_pointer(void *n);

#endif