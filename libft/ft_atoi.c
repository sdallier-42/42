/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:40:25 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/13 13:27:49 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	sign;
	int	nbr;

	a = 0;
	sign = 1;
	nbr = 0;
	while ((str[a] == 32) || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '+')
		a++;
	else if (str[a] == '-')
	{
		sign *= -1;
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		nbr *= 10;
		nbr += str[a] - 48;
		a++;
	}
	return (nbr * sign);
}
