/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzalv <agonzalv@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:04:05 by agonzalv          #+#    #+#             */
/*   Updated: 2023/03/09 17:13:41 by agonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *sr, ...);
int		ft_print_unsigned(unsigned int n);
int		ft_print_string(char *str);
int		ft_print_char(int c);
int		ft_print_decimal(int n);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_print_hexa_l(unsigned int n);
int		ft_print_hexa_u(unsigned int n);
int		ft_print_ptr(void *ptr);

#endif
