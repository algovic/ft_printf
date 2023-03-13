/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:04:33 by agonzalv          #+#    #+#             */
/*   Updated: 2023/03/09 17:14:05 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_size(unsigned int n)
{
	size_t	size;

	size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_uitoa(unsigned int n)
{
	char	*itoa;
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_size(n);
	itoa = (char *)malloc(size + 1);
	if (!itoa)
		return (NULL);
	itoa[size] = '\0';
	while (i < size)
	{
		itoa[size - 1] = (n % 10) + 48;
		n = n / 10;
		size--;
	}
	return (itoa);
}
