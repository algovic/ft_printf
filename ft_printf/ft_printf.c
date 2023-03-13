/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:21:20 by agonzalv          #+#    #+#             */
/*   Updated: 2023/03/09 17:21:54 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == '%')
		len = len + ft_print_char('%');
	else if (format == 'c')
		len = len + ft_print_char(va_arg(args, int));
	else if (format == 's')
		len = len + ft_print_string(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len = len + ft_print_decimal(va_arg(args, int));
	else if (format == 'u')
		len = len + ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		len = len + ft_print_hexa_l(va_arg(args, unsigned int));
	else if (format == 'X')
		len = len + ft_print_hexa_u(va_arg(args, unsigned int));
	else if (format == 'p')
		len = len + ft_print_ptr(va_arg(args, void *));
	else
		return (-1);
	return (len);
}

static	int	ft_printf_bis(va_list args, const char *str)
{
	int	len;
	int	i;
	int	temp;

	temp = 0;
	len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			temp = ft_formats(args, str[i + 1]);
			if (temp == -1)
				return (-1);
			len = len + temp;
			i++;
		}
		else
		{
			if ((write(1, &str[i], 1) != 1))
				return (-1);
			len = len + 1;
		}
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		temp;
	va_list	args;

	temp = 0;
	len = 0;
	va_start(args, str);
	temp = ft_printf_bis(args, str);
	if (temp == -1)
		return (-1);
	len = temp;
	va_end(args);
	return (len);
}
/*
	temp = ft_formats(args, str);
	if (temp == -1)
		return (-1);
#define YE "\x1b[33m"
#define BL "\x1b[36m"
#define GR "\x1b[32m"
#define RESET "\x1b[0m"

int	main(void)
{
	int				len;
	char			a;
	char			b;
	char			c;
	char			*str1;
	char			*str2;
	int				d;
	int				i;
	unsigned int	u;
	int				max;
	int				min;
	int				z;
	void			*ptr;

	ptr = "XXX";
	z = 0;
	max = 2147483647;
	min = -2147483648;
	u = 4294967295;
	d = -1781818164;
	i = 42;
	str1 = "Hello";
	str2 = "World";
	a = 'F';
	b = 'T';
	c = '\0';
	printf(BL "\nFuncion original:\n");
	printf(YE);
	
	printf("\n");
	len = printf("%x", -100);  ////
	printf("\n");
	printf("len= %d\n", len);
	
	len = printf(YE "Hello42 estoy al 100%% y tu al 120%%\n");
	printf("len= %d\n", len);
	
	len = printf("%d", 0);		// fallo retorno
	printf("\n");
	printf("len= %d\n", len);
	
	len = printf("%%"); // fallo retorno -1
	printf("len= %d\n", len);
	
	len = printf("Prueba de caracteres F T -> %c %c %c.-\n", a, b, c);
	printf("len= %d\n", len);
	len = printf("Test String: %s %s %s\n", str1, str2, NULL);
	printf("len= %d\n", len);
	len = printf("Test Decimal/Entero: %d/%i= %d\n", d, i, d / i);
	printf("len= %d\n", len);
	len = printf("Test Unsigned: %u->%u\nTest Int %d->%d->%d\n",0,u,min,0,max);
	printf("len= %d\n", len);
	len = printf("Test Hexa %x -> %x -> %x -> %lx\n", 0, 16, 8116, 4294967295);
	printf("len= %d\n", len);
	len = printf("Test Hexa %X -> %X -> %X -> %lX\n", 0, 16, 8116, 4294967295);
	printf("len= %d\n", len);
	len = printf("Test Ptr %p\n", ptr);
	printf("len= %d\n", len);
	
	printf(BL "\nFuncion ft_printf 42:\n");
	printf(RESET);
	printf(GR);
	
	printf("\n");
	len = ft_printf("%x", -100);  ////
	printf("\n");
	printf("len= %d\n", len);
	
	len = ft_printf(GR "Hello42 estoy al 100%% y tu al 120%%\n");
	printf("len= %d\n", len);
	
	len = ft_printf("%d", 0);		// fallo retorno
	printf("\n");
	printf("len= %d\n", len);

	len = ft_printf("%%"); // fallo retorno -1
	printf("len= %d\n", len);

	len = ft_printf("Prueba de caracteres F T -> %c %c %c.-\n", a, b, c);
	printf("len= %d\n", len);
	len = ft_printf("Test String: %s %s %s\n", str1, str2, NULL);
	printf("len= %d\n", len);
	len = ft_printf("Test Decimal/Entero: %d/%i= %d\n", d, i, d / i);
	printf("len= %d\n", len);
	len = ft_printf("Test Unsigned: %u->%u\nTest Int %d->%d->%d\n",0,u,min,0,max);
	printf("len= %d\n", len);
	len = ft_printf("Test Hexa %x -> %x -> %x -> %x\n", 0, 16, 8116, 4294967295);
	printf("len= %d\n", len);
	len = ft_printf("Test Hexa %X -> %X -> %X -> %X\n", 0, 16, 8116, 4294967295);
	printf("len= %d\n", len);
	len = ft_printf("Test Ptr %p\n", ptr);
	printf("len= %d\n", len);

	printf(RESET "\n");
	return (0);
}
*/
