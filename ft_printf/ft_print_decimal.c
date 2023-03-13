/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:01:27 by agonzalv          #+#    #+#             */
/*   Updated: 2023/03/09 17:11:49 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(int n)
{
	char	*str;
	int		len;

	if (n == 0)
	{
		if ((write(1, "0", 1) != 1))
			return (-1);
		return (1);
	}
	str = ft_itoa(n);
	if (!str)
		return (-1);
	len = ft_print_string(str);
	free(str);
	return (len);
}
