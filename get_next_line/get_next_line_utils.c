/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:42:51 by sdallier          #+#    #+#             */
/*   Updated: 2025/12/01 13:57:23 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char *str)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
	{
		if (str[a] == '\n')
			return (&str[a]);
		a++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t		a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char	*ft_strjoin(char *temp, char *buffer)
{
	int		a;
	int		b;
	char	*tmp;

	if (!temp && !buffer)
		return (NULL);
	if (!temp)
		temp = ft_calloc(1, sizeof(char));
	tmp = malloc(sizeof(char) * (ft_strlen(temp) + ft_strlen(buffer) + 1));
	if (!tmp)
		return (NULL);
	a = -1;
	while (temp[++a])
		tmp[a] = temp[a];
	b = -1;
	while (buffer[++b])
		tmp[a++] = buffer[b];
	tmp[a] = '\0';
	return (free(temp), free(buffer), tmp);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*total;
	size_t	a;

	total = malloc(count * size);
	if (!total)
		return (NULL);
	a = 0;
	while (a < size * count)
	{
		total[a] = 0;
		a++;
	}
	return (total);
}
