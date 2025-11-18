/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:58:08 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/17 14:03:38 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	long	a;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		a = 0;
		while ((size_t)a < len)
		{
			*(unsigned char *)(dest + a) = *(unsigned char *)(src + a);
			a++;
		}
		return (dest);
	}
	else
	{
		a = len - 1;
		while (a >= 0)
		{
			*(unsigned char *)(dest + a) = *(unsigned char *)(src + a);
			a--;
		}
		return (dest);
	}
}
