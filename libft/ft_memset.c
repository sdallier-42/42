/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:51:23 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/17 13:59:32 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	a;

	// if (!b)
	// 	return (NULL);
	a = 0;
	while (a < len)
	{
		*(unsigned char *)(b + a) = (unsigned char)c;
		a++;
	}
	return (b);
}
