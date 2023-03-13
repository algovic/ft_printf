/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:00:32 by agonzalv          #+#    #+#             */
/*   Updated: 2023/03/09 17:11:10 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_size(long long n)
{
	size_t	size;

	if (n < 0)
		size = 1;
	else
		size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	size_t	i;
	long	num;
	size_t	size;

	i = 0;
	num = n;
	size = ft_size(num);
	itoa = (char *)malloc(sizeof(char) * size + 1);
	if (!itoa)
		return (NULL);
	itoa[size] = '\0';
	if (num < 0)
	{
		itoa[0] = '-';
		num = num * -1;
		i++;
	}
	while (i < size)
	{
		itoa[size - 1] = (num % 10) + 48;
		num = num / 10;
		size--;
	}
	return (itoa);
}
