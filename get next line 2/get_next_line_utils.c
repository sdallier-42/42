/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:20:09 by sdallier          #+#    #+#             */
/*   Updated: 2025/12/02 12:14:04 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
		a++;
	return (a);
}

char	*ft_strchr(char *str, int c)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[a])
	{
		if (str[a] == (char) c)
			return ((char *)&str[a]);
		a++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buffer)
{
	char	*s;
	size_t	a;
	size_t	b;

	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	s = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buffer)) + 1));
	if (!s)
		return (NULL);
	a = -1;
	b = 0;
	if (str)
		while (str[++a])
			s[a] = str[a];
	while (buffer[b])
		s[a++] = buffer[b++];
	s[ft_strlen(str) + ft_strlen(buffer)] = '\0';
	free(str);
	return (s);
}
