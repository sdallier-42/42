/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:42:53 by sdallier          #+#    #+#             */
/*   Updated: 2025/12/01 15:35:36 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static char	*cpy_buff(int fd, char *temp)
// {
// 	char	*buffer;
// 	char	*tmp;
// 	int		bytes;

// 	bytes = 1;
// 	while (!new_line(temp) && bytes != 0)
// 	{
// 		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 		if (!buffer)
// 			return (NULL);
// 		bytes = read(fd, buffer, BUFFER_SIZE);
// 		if ((!temp && bytes == 0) || bytes == -1)
// 			return (free(buffer), NULL);
// 		buffer[bytes] = '\0';
// 		tmp = ft_strjoin(temp, buffer);
// 		if (!tmp)
// 			return (free(temp), NULL);
// 		temp = tmp;
// 	}
// 	return (temp);
// }

// static char	*trim_temp(char	*temp, char *line)
// {
// 	int		a;
// 	int		b;
// 	char	*keep_temp;

// 	if (!temp)
// 		return (free(temp), NULL);
// 	a = ft_strlen(line);
// 	b = 0;
// 	while (temp[a++])
// 		b++;
// 	keep_temp = malloc(sizeof(char) * (b + 1));
// 	if (!keep_temp)
// 		return (free(temp), NULL);
// 	a = ft_strlen(line);
// 	b = 0;
// 	while (temp[a])
// 		keep_temp[b++] = temp[a++];
// 	keep_temp[b] = '\0';
// 	free(temp);
// 	return (keep_temp);
// }

// static char	*extract_line(char *temp)
// {
// 	int		a;
// 	char	*line;

// 	if (!temp)
// 		return (NULL);
// 	a = 0;
// 	while (temp[a] && temp[a] != '\n')
// 		a++;
// 	line = malloc(sizeof(char) * (a + 2));
// 	if (!line)
// 	{
// 		free(temp);
// 		temp = NULL;
// 		return (NULL);
// 	}
// 	a = -1;
// 	while (temp[++a] && temp[a] != '\n')
// 		line[a] = temp[a];
// 	if (temp[a] == '\n')
// 		line[a++] = '\n';
// 	line[a] = '\0';
// 	return (line);
// }

void	ft_extract(char	**ptr)
{
	char	*keep_tmp;

	keep_tmp = ft_strdup(ft_strchr(*ptr, '\n') + 1);
	free(*ptr);
	*ptr = keep_tmp;
}

char	*ft_new_line(char **ptr_tmp, char **ptr_buff, size_t b)
{
	char	*line;

	line = NULL;
	if (*ptr_tmp && *ptr_buff && b == 0)
	{
		line = ft_strdup(*ptr_tmp);
		free(*ptr_tmp);
		*ptr_tmp = NULL;
		free(*ptr_buff);
		*ptr_buff = NULL;
		return (line);
	}
	if (ft_strchr(*ptr_tmp, '\n') != NULL)
	{
		line = ft_substr(*ptr_tmp, 0, ft_strlen(*ptr_tmp) \
			- ft_strlen(ft_strchr(*ptr_tmp, '\n')));
		ft_extract(ptr_tmp);
		return (line);
	}
	free(*ptr_tmp);
	*ptr_tmp = NULL;
	free(*ptr_buff);
	*ptr_buff = NULL;
	return (NULL);
}

char	*ft_check(char *tmp, char *buffer)
{
	char	*keep_tmp;
	int		len;

	len = 0;
	keep_tmp = NULL;
	if (tmp)
	{
		keep_tmp = ft_strdup(tmp);
		free(tmp);
		len = ft_strlen(keep_tmp) + ft_strlen(buffer);
		tmp = (char *)malloc(len + 1);
		if (!tmp)
			return (NULL);
		ft_memcpy(tmp, keep_tmp, ft_strlen(keep_tmp + 1));
		tmp[ft_strlen(keep_tmp)] = '\0';
		ft_memcpy(ft_strchr(tmp, '\0'), buffer, ft_strlen(buffer));
		tmp[len] = '\0';
		free(keep_tmp);
	}
	else if (!tmp)
		tmp = ft_strdup(buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char		*tmp;
	char			*buffer;
	size_t			bytes;

	buffer = NULL;
	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (bytes != 0)
	{
		if (ft_strchr(tmp, '\n') != NULL)
			return (ft_new_line(&tmp, &buffer, bytes));
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		tmp = ft_check(tmp, buffer);
		free(buffer);
		buffer = NULL;
	}
	return (ft_new_line(&tmp, &buffer, bytes));
}
