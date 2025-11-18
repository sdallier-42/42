/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:22:49 by suziedallie       #+#    #+#             */
/*   Updated: 2025/11/13 15:02:07 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;
	size_t	l;

	if (!*little)
		return ((char *)big);
	a = 0;
	l = ft_strlen(little);
	while (big[a] && (a + l - 1) < len)
	{
		b = 0;
		while (little[b] && big[a + b] == little[b])
		{
			if (b == (l - 1))
				return ((char *)(big + a));
			b++;
		}
		a++;
	}
	return (0);
}
