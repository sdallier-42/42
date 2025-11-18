/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:16:35 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/14 13:17:10 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n && *(unsigned char *)(s1 + a) == *(unsigned char *)(s2 + a))
		a++;
	if (a < n)
		return (*(unsigned char *)(s1 + a) - *(unsigned char *)(s2 + a));
	return (0);
}
