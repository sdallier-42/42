/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:29:20 by sdallier          #+#    #+#             */
/*   Updated: 2025/12/03 11:43:01 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*init_line(char *keep, int *bytes)
{
	size_t	i;
	char	*line;

	i = 0;
	while (keep[i] && keep[i] != '\n')
		i++;
	i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_memcpy(line, keep, i);
	line[i] = '\0';
	if (i > 0 && line[i - 1] == '\n')
		*bytes = i - 1;
	return (line);
}

size_t	line_len(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (-1);
	while (i < BUFFER_SIZE)
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*extract_line(char *line, char *keep, int *bytes, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	read_check;
	size_t	line_size;

	while (*bytes == -1)
	{
		ft_bzero(buffer, (BUFFER_SIZE + 1));
		read_check = read(fd, buffer, BUFFER_SIZE);
		if (read_check == -1)
		{
			free(line);
			ft_bzero(keep, (BUFFER_SIZE + 1));
			return (NULL);
		}
		line_size = line_len(buffer);
		ft_strlcpy(keep, &buffer[line_size], (BUFFER_SIZE + 1));
		buffer[line_size] = '\0';
		line = ft_strjoin(line, buffer, bytes);
		if (read_check == 0)
		{
			ft_bzero(keep, BUFFER_SIZE + 1);
			break ;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	keep[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = -1;
	line = init_line(keep, &bytes);
	if (!line)
		return (NULL);
	ft_strlcpy(keep, &keep[bytes + 1], BUFFER_SIZE + 1);
	line = extract_line(line, keep, &bytes, fd);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
