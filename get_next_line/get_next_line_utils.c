/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:42:51 by sdallier          #+#    #+#             */
/*   Updated: 2025/12/01 15:36:17 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t		a;

	a = 0;
	while (str[a])
		a++;
	return (a);
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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	a;

	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	a = 0;
	while (start + a < ft_strlen(s) && a < len)
	{
		sub[a] = s[start + a];
		a++;
	}
	sub[a] = '\0';
	return (sub);
}
