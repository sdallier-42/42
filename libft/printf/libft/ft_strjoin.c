/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:35:53 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/17 13:32:01 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		a;
	int		b;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(*s1) * (len + 1));
	if (!dest)
		return (NULL);
	a = 0;
	b = 0;
	while (s1[a])
	{
		dest[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		dest[a + b] = s2[b];
		b++;
	}
	dest[a + b] = '\0';
	return (dest);
}
