/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:32:29 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/26 14:00:09 by sdallier         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		a;
	int		b;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
		return (NULL);
	a = -1;
	while (s1[++a])
		dest[a] = s1[a];
	b = 0;
	while (s2[b])
		dest[a++] = s2[b++];
	dest[a] = '\0';
	return (free(s1), dest);
}

char	*ft_strchr(char *str, int c)
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
