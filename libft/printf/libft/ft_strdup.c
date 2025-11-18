/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:00:19 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/12 13:28:42 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		a;
	char	*dest;

	a = 0;
	while (src[a])
		a++;
	dest = (char *)malloc(sizeof(char) * (a + 1));
	if (!dest)
		return (NULL);
	a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
	dest [a] = '\0';
	return (dest);
}
