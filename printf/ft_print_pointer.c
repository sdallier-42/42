/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:57:36 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/20 12:48:11 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long value)
{
	char	str[17];
	int		a;
	int		len;

	if (value == 0)
		return (write(1, "(nil)", 5));
	a = 16;
	str[a] = '\0';
	while (value)
	{
		a--;
		if ((value % 16) < 10)
			str[a] = (value % 16) + '0';
		else
			str[a] = (value % 16) - 10 + 'a';
		value /= 16;
	}
	len = 16 - a;
	write(1, "0x", 2);
	write(1, str + a, len);
	return (len + 2);
}
