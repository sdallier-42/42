/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:56:43 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/17 14:03:04 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	a;

	if (!dest && !src)
		return (NULL);
	a = 0;
	while (a < n)
	{
		*(unsigned char *)(dest + a) = *(unsigned char *)(src + a);
		a++;
	}
	return (dest);
	
}
