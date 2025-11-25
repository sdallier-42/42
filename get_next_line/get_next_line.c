/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:22:14 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/25 14:01:11 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_error(int fd, int bytes, char *buffer)
{
	if (fd < 0)
		return (0);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1)))
		return (0);
	if (bytes < 0)
	{
		free(buffer);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	c;
	int		a;
	int		bytes;

	buffer = (char *)malloc(sizeof (char) * (BUFFER_SIZE) + 1);
	if (!buffer)
		return (NULL);
	bytes = read(fd, &c, 1);
	a = 0;
	while (bytes > 0)
	{
		buffer[a++] = c;
		if (c == '\n' || c == EOF)
			break ;
		bytes = read(fd, &c, 1);
	}
	if (!check_error(fd, bytes, buffer) || a == 0)
		return (NULL);
	buffer[a] = '\0';
	return (buffer);
}
// int	main(void)
// {
// 	int	fd;
// 	char	*str;
// 	char	*path;
// 	int		a;

// 	path = "test.txt";
// 	fd = open(path, O_RDONLY);
// 	a = 0;
// 	while (a <10)
// 	{
// 		str = get_next_line(fd);
// 		printf("i: %i\n", a);
// 		printf("fd: %i, %s\n", fd, str);
// 		a++;
// 	}
// 	return (0);
// }
