/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:32:29 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/26 13:30:31 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t		a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

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

char	*ft_strchr(const char *str, int c)
{
	size_t	a;

	a = 0;
	while (str[a])
	{
		if (str[a] == (char) c)
			break ;
		a++;
	}
	if (str[a] == (char) c)
		return ((char *) str + a);
	return (NULL);
}
