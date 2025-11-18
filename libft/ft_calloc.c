/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:27:15 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/12 13:27:51 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*total;
	size_t	a;

	total = malloc(count * size);
	if (!total)
		return (NULL);
	a = 0;
	while (a < size * count)
	{
		total[a] = 0;
		a++;
	}
	return (total);
}
