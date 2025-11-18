/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:29:37 by suziedallie       #+#    #+#             */
/*   Updated: 2025/11/13 15:17:43 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	inset(char c, const char *set)
{
	int	a;

	a = 0;
	while (set[a])
	{
		if (c == set[a])
			return (1);
		a++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*dest;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && inset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && inset(s1[end - 1], set))
		end--;
	dest = ft_substr(s1, start, end - start);
	return (dest);
}

// #include <stdio.h>

// int main(void)
// {
// 	char *trimmed = ft_strtrim("abcd123ab123bda", "abcd");
// 	printf("'%s'\n", trimmed);
// 	free(trimmed);
// }