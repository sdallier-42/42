/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:22:14 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/26 13:57:11 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *temp)
{
	int		a;
	char	*line;

	if (!temp[0] || !temp)
		return (NULL);
	a = 0;
	while (temp[a] && temp[a] != '\n')
		a++;
	if (temp[a] == '\n')
		a++;
	line = malloc(a + 1);
	if (!line)
		return (NULL);
	a = 0;
	while (temp[a] && temp[a] != '\n')
	{
		line[a] = temp[a];
		a++;
	}
	if (temp[a] == '\n')
		line[a++] = '\n';
	line[a] = '\0';
	return (line);
}

static char	*trim_temp(char	*temp)
{
	int		a;
	int		b;
	char	*new_temp;

	if (!temp)
		return (NULL);
	a = 0;
	while (temp[a] && temp[a] != '\n')
		a++;
	if (!temp[a])
		return (free(temp), NULL);
	new_temp = malloc(ft_strlen(temp) - a);
	if (!new_temp)
		return (NULL);
	a++;
	b = 0;
	while (temp[a])
		new_temp[b++] = temp[a++];
	new_temp[b] = '\0';
	free(temp);
	return (new_temp);
}

static char	*read_to_temp(int fd, char *temp)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!temp)
	{
		temp = malloc(1);
		if (!temp)
			return (free(buffer), NULL);
		temp[0] = '\0';
	}
	while (temp && !ft_strchr(temp, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(temp), NULL);
		buffer[bytes] = '\0';
		temp = ft_strjoin(temp, buffer);
		if (!temp)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_to_temp(fd, temp);
	if (!temp)
		return (NULL);
	line = extract_line(temp);
	temp = trim_temp(temp);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("LINE => %s", line);
// 		free(line);
// 	}

// 	close(fd);
// 	return (0);
// }
