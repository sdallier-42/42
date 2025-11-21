/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:11:25 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/20 12:20:26 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_nb(unsigned int nb)
{
	if (nb > 9)
		ft_print_unsigned(nb / 10);
	if (nb <= 9)
	{
		ft_putchar_fd(nb + 48, 1);
		return ;
	}
	ft_putchar_fd((nb % 10) + 48, 1);
}

int	ft_print_unsigned(unsigned int nb)
{
	unsigned int	a;

	ft_print_nb(nb);
	a = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		a++;
	}
	return (a);
}
