/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:57:42 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/18 13:42:26 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_int(int n)
{
	int				nb;
	unsigned int	a;

	nb = n;
	a = 1;
	if (n < 0 && n != -2147483648)
	{
		nb = -n;
		a++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		a++;
	}
	ft_putnbr_fd(n, 1);
	if (n == -2147483648)
		return (11);
	return (a);
}
