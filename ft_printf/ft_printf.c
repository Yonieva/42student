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
	return (write(1, &c, 1));
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

int	print_nbr(long n, int base)
{
	int count;
	char	*base16;

	base16 = "0123456789abcdef";
	if (n < 0)
	{
		print_char('-');
		return (print_nbr(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(base16[n]));
	else
	{
		count = print_nbr(n / base, base);
		return (count + print_nbr(n % base, base));
	}
}

int	print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = count + print_char(va_arg(args, int));
	else if (specifier == 's')
		count = count + print_str(va_arg(args, char *));
	else if (specifier == 'd')
		count = count + print_nbr((long)va_arg(args, int), 10);
	else if (specifier == 'x')
		count = count + print_nbr((long)va_arg(args, unsigned int), 16);
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
		{
			i++;
			count = count + print_format(format[i++], args);
		}
		else
		{
			count = count + print_char(format[i]);
			i++;
		}
	}
	va_end(args);
	return count;
}



int	main()
{
	int testint;
	int	test_neg_int;
	int	testhexa;
	char testchar;
	char *teststr;
	
	testint = 142;
	test_neg_int = -2147483648;
	testhexa = 1968;
	testchar = 'c';
	teststr = "Salut Bg !";

	ft_printf("Voici un test de ma fonction avec un int : %d\n", testint);
	printf("Voici un test de la vrai fonction avec un int : %d\n\n", testint);
    ft_printf("Voici un test de ma fonction avec un int negatif : %d\n", test_neg_int);
    printf("Voici un test de la vrai fonction avec un int negatif : %d\n\n", test_neg_int);
    ft_printf("Voici un test de ma fonction avec un char : %c\n", testchar);
    printf("Voici un test de la vrai fonction avec un char : %c\n\n", testchar);
    ft_printf("Voici un test de ma fonction avec une string : %s\n", teststr);
    printf("Voici un test de la vrai fonction avec une string : %s\n\n", teststr);
 	ft_printf("Voici un test de ma fonction avec un hexa : %x\n", testhexa);
    printf("Voici un test de la vrai fonction avec un hexa : %x\n\n", testhexa);

}


