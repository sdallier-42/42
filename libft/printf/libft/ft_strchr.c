/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:03:20 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/12 13:04:37 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	a;

	a = 0;
	while (str[a])
	{
		if (str[a] == (char) c)
			break ;
		a++;
	}
	if (str[a] == (char) c)
		return ((char *) str + a);
	return (NULL);
}
