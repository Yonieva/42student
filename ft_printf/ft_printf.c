/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonieva <yonieva@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:24:12 by yonieva           #+#    #+#             */
/*   Updated: 2023/11/06 14:59:08 by yonieva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h> //va_
#include <unistd.h>
#include <stdio.h> //remove before push
#include <stdlib.h>

int	print_char(int c)
{
	return write(1, &c, 1);
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		print_char((int)str[i]);
		i++;
	}
	return (i);
}




int	print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = count + print_char(va_arg(args, int));
	else if (specifier == 's')
		count = print_str(va_arg(args, char *));
	else if (specifier == 'd')
		count = print_digit(va_arg(args, int), 10);
	else if (specifier == 'x')
		count = count + print_digit(va_arg(args, unsigned int), 16);
	else
		count = count + write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ... )
{
	va_list	args;
	int		i;
	int		count;
	
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			count = count + print_format(format[i++], args);
		else
		{
			count = count + write(1, format[i], 1);
			i++;
		}
	}
	va_end(args);
	return count;
}
