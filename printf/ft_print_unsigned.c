/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:11:25 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/18 13:43:22 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_print(unsigned int nb)
{
	if (nb > 9)
		ft_print_unsigned(nb / 10);
	if (nb <= 9)
	{
		ft_putchar_fd(nb + 48, 1);
		return ;
	}
	ft_putchar_fd((nb % 16) + 48, 1);
}

int	ft_print_unsigned(unsigned int nb)
{
	unsigned int	a;

	ft_print(nb);
	a = 1;
	while (nb > 9)
	{
		nb /= 10;
		a++;
	}
	return (a);
}
