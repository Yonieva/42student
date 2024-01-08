/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:46:19 by yonieva           #+#    #+#             */
/*   Updated: 2023/11/08 12:46:19 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	print_char(int c);
int	print_str(char *str);
int	print_nbr(long n, int base);
int	printxup(long n, int base);
int	print_ptr(void *ptr);
int	print_format(char specifier, va_list args);
int	ft_printf(const char *format, ...);

#endif
