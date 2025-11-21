/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:02:13 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/20 11:04:40 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*new_str(unsigned int value, int *strlen)
{
	int				a;
	unsigned int	temp;
	char			*str;

	a = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / 16;
		a++;
	}
	str = calloc(a + 1, sizeof(char));
	*strlen = a - 1;
	return (str);
}

int	ft_print_hex(unsigned int value, int n)
{
	unsigned int	temp;
	char			*print;
	int				a;
	int				*ptr;

	ptr = &a;
	temp = value;
	print = new_str(value, ptr);
	if (!print)
		return (0);
	while (temp != 0)
	{
		if ((temp % 16) < 10)
			print[a] = (temp % 16) + 48;
		else
			print[a] = (temp % 16) + n;
		temp = temp / 16;
		a--;
	}
	ft_putstr_fd(print, 1);
	a = ft_strlen(print);
	free(print);
	if (value == 0)
		a += ft_print_char('0');
	return (a);
}
