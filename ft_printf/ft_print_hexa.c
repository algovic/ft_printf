/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:01:53 by agonzalv          #+#    #+#             */
/*   Updated: 2023/03/09 17:12:07 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_len_hexa(unsigned int n)
{
	int		len;

	len = 0;
	if (!n)
		return (-1);
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static char	*ft_itoa_hexa_l(unsigned int nb)
{
	int					size;
	unsigned long int	n;
	char				*hexa;

	n = (unsigned long int)nb;
	size = ft_len_hexa(n);
	hexa = (char *)malloc(sizeof(char) * (size + 1));
	if (!hexa)
		return (NULL);
	hexa[size] = '\0';
	while (size != 0)
	{
		hexa[size - 1] = "0123456789abcdef"[n % 16];
		n = n / 16;
		size--;
	}
	return (hexa);
}

static char	*ft_itoa_hexa_u(unsigned int nb)
{
	int					size;
	unsigned long int	n;
	char				*hexa;

	n = (unsigned long int)nb;
	size = ft_len_hexa(n);
	hexa = (char *)malloc(sizeof(char) * (size + 1));
	if (!hexa)
		return (NULL);
	hexa[size] = '\0';
	while (size != 0)
	{
		hexa[size - 1] = "0123456789ABCDEF"[n % 16];
		n = n / 16;
		size--;
	}
	return (hexa);
}

int	ft_print_hexa_l(unsigned int n)
{
	char	*hexa;
	int		len;

	if (n == 0)
	{
		if ((write(1, "0", 1)) != 1)
			return (-1);
		return (1);
	}
	hexa = ft_itoa_hexa_l(n);
	if (!hexa)
		return (-1);
	len = ft_print_string(hexa);
	free(hexa);
	return (len);
}

int	ft_print_hexa_u(unsigned int n)
{
	char	*hexa;
	int		len;

	if (n == 0)
	{
		if ((write(1, "0", 1)) != 1)
			return (-1);
		return (1);
	}
	hexa = ft_itoa_hexa_u(n);
	if (!hexa)
		return (-1);
	len = ft_print_string(hexa);
	free(hexa);
	return (len);
}
