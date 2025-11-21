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

// static char	*new_str(unsigned long value, int *strlen)
// {
// 	int				a;
// 	unsigned long	temp;
// 	char			*str;

// 	a = 0;
// 	temp = value;
// 	while (temp != 0)
// 	{
// 		temp = temp / 16;
// 		a++;
// 	}
// 	str = calloc(a + 1, sizeof(char));
// 	*strlen = a - 1;
// 	return (str);
// }

int	ft_print_pointer(unsigned long value)
{
	char	str[17];
	int		a;
	int		len;

	if (value == 0)
		return (write(1, "0x0", 3));
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
