/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:24:12 by yonieva           #+#    #+#             */
/*   Updated: 2023/11/02 22:24:14 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_printf(const char *format, ... )
{
	va_list	args;
	int		i;
	int		count;
	
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count = count + print_format(format[i++], args);
		else
			count = count + write(1, format[i], 1);
			i++;
	}
	va_end(args);
	return count;
}
