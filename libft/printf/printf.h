/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:36:30 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/18 13:40:35 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int	ft_print_char(char c);
int	ft_print_int(int n);
int	ft_print_hex(unsigned int value, int n);
int	ft_print_pointer(unsigned long value, int n);
int	ft_print_string(char *s);
int	ft_print_unsigned(unsigned int nb);
int	ft_printf(const char *input, ...);

#endif