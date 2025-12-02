/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:20:12 by sdallier          #+#    #+#             */
/*   Updated: 2025/12/02 11:48:59 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int		a;
	char	*line;

	a = 0;
	if (!str[a])
		return (NULL);
	while (str[a] && str[a] != '\n')
		a++;
	line = (char *)malloc(sizeof(char) * (a + 2));
	if (!line)
		return (NULL);
	a = 0;
	while (str[a] && str[a] != '\n')
	{
		line[a] = str[a];
		a++;
	}
	if (str[a] == '\n')
	{
		line[a] = str[a];
		a++;
	}
	line[a] = '\0';
	return (line);
}

char	*ft_new_str(char *str)
{
	int		a;
	int		b;
	char	*line;

	a = 0;
	while (str[a] && str[a] != '\n')
		a++;
	if (!str[a])
	{
		free(str);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(str) - a + 1));
	if (!line)
		return (NULL);
	a++;
	b = 0;
	while (str[a])
		line[b++] = str[a++];
	line[b] = '\0';
	free(str);
	return (line);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_new_str(str);
	return (line);
}
