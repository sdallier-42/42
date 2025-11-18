/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:23:10 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/18 13:55:48 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_check(const char *input, void *arg)
{
	int	a;

	a = 0;
	if (*input == 'c')
		a += ft_print_char((char)arg);
	else if (*input == 's')
		a += ft_print_string((char *)arg);
	else if (*input == 'p')
		a += ft_print_pointer((unsigned long)arg, 87);
	else if (*input == 'd')
		a += ft_print_int((int)arg);
	else if (*input == 'i')
		a += ft_print_int((int)arg);
	else if (*input == 'u')
		a += ft_print_unsigned((unsigned int)arg);
	else if (*input == 'x')
		a += ft_print_hex((unsigned int)arg, 87);
	else if (*input == 'X')
		a += ft_print_hex((unsigned int)arg, 55);
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
			if (ft_strchr("cspdiuxX", *input))
				a += ft_check(input, va_arg(arg, void *));
			else if (*input == '%')
				a += ft_print_char('%');
		}
		else
			a = a + ft_print_char(*input);
		input++;
	}
	va_end(arg);
	return (a);
}
