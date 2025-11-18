/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:15:36 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/14 13:02:46 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	a;

	if (size == 0)
		return (ft_strlen(src));
	a = 0;
	while (src[a] && a < size - 1)
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (ft_strlen(src));
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	src[] = "hello";
// 	char	dest[100];
// 	printf("%d\n", ft_strlcpy(dest, src, 2));
// 	return (0);
// }