/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:42:53 by sdallier          #+#    #+#             */
/*   Updated: 2025/12/01 14:00:03 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cpy_buff(int fd, char *temp)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	while (!new_line(temp) && bytes != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if ((!temp && bytes == 0) || bytes == -1)
			return (free(buffer), NULL);
		buffer[bytes] = '\0';
		temp = ft_strjoin(temp, buffer);
	}
	return (temp);
}

static char	*trim_temp(char	*temp, char *line)
{
	int		a;
	int		b;
	char	*keep_temp;

	if (!temp)
		return (free(temp), NULL);
	a = ft_strlen(line);
	b = 0;
	while (temp[a++])
		b++;
	keep_temp = malloc(sizeof(char) * (b + 1));
	if (!keep_temp)
		return (NULL);
	a = ft_strlen(line);
	b = 0;
	while (temp[a])
		keep_temp[b++] = temp[a++];
	keep_temp[b] = '\0';
	free(temp);
	return (keep_temp);
}

static char	*extract_line(char *temp)
{
	int		a;
	char	*line;

	if (!temp)
		return (NULL);
	a = 0;
	while (temp[a] && temp[a] != '\n')
		a++;
	line = malloc(sizeof(char) * (a + 2));
	if (!line)
		return (NULL);
	a = -1;
	while (temp[++a] && temp[a] != '\n')
		line[a] = temp[a];
	if (temp[a] == '\n')
		line[a++] = '\n';
	line[a] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = cpy_buff(fd, temp);
	if (!tmp)
	{
		if (temp)
			free(temp);
		temp = NULL;
		return (NULL);
	}
	temp = tmp;
	line = extract_line(temp);
	temp = trim_temp(temp, line);
	return (line);
}
