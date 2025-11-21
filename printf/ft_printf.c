/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:23:10 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/20 12:48:29 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(const char *input, va_list args)
{
	int	a;

	a = 0;
	if (*input == 'c')
		a += ft_print_char(va_arg(args, int));
	else if (*input == 's')
		a += ft_print_string(va_arg(args, char *));
	else if (*input == 'p')
		a += ft_print_pointer(va_arg(args, unsigned long));
	else if (*input == 'd')
		a += ft_print_int(va_arg(args, int));
	else if (*input == 'i')
		a += ft_print_int(va_arg(args, int));
	else if (*input == 'u')
		a += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*input == 'x')
		a += ft_print_hex(va_arg(args, unsigned int), 87);
	else if (*input == 'X')
		a += ft_print_hex(va_arg(args, unsigned int), 55);
	return (a);
}

int	ft_printf(const char *input, ...)
{
	va_list			arg;
	unsigned int	a;

	a = 0;
	va_start(arg, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX%", *input))
			{
				if (*input == '%')
					a += ft_print_char('%');
				else
					a += ft_check(input, arg);
			}
		}
		else
			a = a + ft_print_char(*input);
		input++;
	}
	va_end(arg);
	return (a);
}
