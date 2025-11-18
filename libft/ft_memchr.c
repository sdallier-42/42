/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:14:33 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/14 13:16:47 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		if (*(unsigned char *)(str + a) == (unsigned char)c)
			return ((void *)(str + a));
		a++;
	}
	return (NULL);
}
