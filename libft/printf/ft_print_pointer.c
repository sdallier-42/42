/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:57:36 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/18 13:40:56 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

int	ft_print_pointer(unsigned long value, int n)
{
	unsigned long	temp;
	char			*print;
	int				a;
	int				*ptr;

	ptr = &a;
	temp = value;
	print = new_str(value, ptr);
	if (!print)
		return (0);
	while (temp != 0 && a-- >= 0)
	{
		if ((temp % 16) < 10)
			print[a + 1] = (temp % 16) + 48;
		else
			print[a + 1] = (temp % 16) + n;
		temp /= 16;
	}
	a = ft_strlen(print);
	a = a + ft_print_string("0");
	ft_putstr_fd(print, 1);
	free (print);
	if (value == 0)
		return ('0');
	return (a);
}
