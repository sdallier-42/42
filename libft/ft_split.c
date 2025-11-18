/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:59:42 by suziedallie       #+#    #+#             */
/*   Updated: 2025/11/17 13:44:57 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *s, char c)
{
	int		count;
	int		a;

	count = 0;
	a = 0;
	while (s[a])
	{
		if ((s[a + 1] == c || s[a + 1] == '\0') && s[a] != c)
			count++;
		a++;
	}
	return (count);
}

static int	ft_wordsize(const char *s, char c)
{
	int	a;

	a = 0;
	while (s[a] && s[a] != c)
	{
		a++;
	}
	return (a);
}

static void	*free_tab(char **tab)
{
	size_t	a;

	a = 0;
	while (tab[a])
	{
		free(tab[a]);
		a++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_malloc_tab(char const *s, char c)
{
	char	**tab;
	int		size;

	if (!s)
		return (NULL);
	size = ft_countwords(s, c) + 1;
	tab = (char **)malloc(sizeof(char *) * size);
	if (!tab)
		return (NULL);
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		a;
	int		b;

	tab = ft_malloc_tab(s, c);
	if (!tab)
		return (0);
	a = 0;
	b = 0;
	while (s[a])
	{
		if (s[a] != c)
		{
			tab[b] = (char *)malloc(sizeof(char) * (ft_wordsize(&s[a], c) + 1));
			if (!tab[b])
				return (free_tab(tab));
			ft_strlcpy(tab[b], (char *)&s[a], ft_wordsize(&s[a], c) + 1);
			a = a + ft_wordsize(&s[a], c);
			b++;
		}
		else
			a++;
	}
	tab[b] = NULL;
	return (tab);
}


// #include <stdio.h>
// int main(void)
// {
//     char **arr = ft_split("Hello world  this is   42 ", ' ');
//     int i = 0;

//     while (arr[i])
//     {
//         printf("%s\n", arr[i]);
//         free(arr[i]);
//         i++;
//     }
//     free(arr);
// }