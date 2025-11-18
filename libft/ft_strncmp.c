/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:24:12 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/14 13:14:46 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	a;

	a = 0;
	if (n == 0)
		return (0);
	while ((a < n - 1) && s1[a] && s1[a] == s2[a])
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
