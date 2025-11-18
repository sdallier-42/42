/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:46:02 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/17 14:07:03 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	a;

	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	a = 0;
	if (size <= len_d)
		return (len_s + size);
	while (len_d + a < size - 1 && src[a])
	{
		dest[len_d + a] = src[a];
		a++;
	}
	dest[len_d + a] = '\0';
	return (len_d + len_s);
}
