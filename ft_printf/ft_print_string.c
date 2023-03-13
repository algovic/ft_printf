/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:02:34 by agonzalv          #+#    #+#             */
/*   Updated: 2023/03/09 17:12:32 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	len;

	if (!str)
	{
		if ((write(1, "(null)", 6)) != 6)
			return (-1);
		return (6);
	}
	len = 0;
	while (str[len])
	{
		if ((write(1, &str[len], 1)) != 1)
			return (-1);
		len++;
	}
	return (len);
}
