/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:02:10 by agonzalv          #+#    #+#             */
/*   Updated: 2023/03/09 17:12:20 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_ptr(unsigned long long n)
{
	int	len;

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

static int	ft_print_ptr_hexa(unsigned long long n)
{
	if (n >= 16)
		ft_print_ptr_hexa(n / 16);
	if ((write(1, &"0123456789abcdef"[n % 16], 1)) != 1)
		return (-1);
	return (0);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long	p;

	p = (unsigned long long)ptr;
	if ((write(1, "0x", 2)) != 2)
		return (-1);
	if (p == 0)
	{
		if ((write(1, "0", 1)) != 1)
			return (-1);
		return (3);
	}
	else
		ft_print_ptr_hexa(p);
	return (ft_len_ptr(p) + 2);
}
