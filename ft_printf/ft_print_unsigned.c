/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:02:58 by agonzalv          #+#    #+#             */
/*   Updated: 2023/03/09 17:12:48 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	char	*str;
	int		len;

	if (n == 0)
	{
		if ((write(1, "0", 1) != 1))
			return (-1);
		return (1);
	}
	str = ft_uitoa(n);
	if (!str)
		return (-1);
	len = ft_print_string(str);
	free(str);
	return (len);
}
