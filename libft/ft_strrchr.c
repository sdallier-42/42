/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:09:27 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/17 14:11:41 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		a;

	a = ft_strlen(str);
	while (a >= 0)
	{
		if (str[a] == (char)c)
			return ((char *)(str + a));
		a--;
	}
	return (NULL);
}
