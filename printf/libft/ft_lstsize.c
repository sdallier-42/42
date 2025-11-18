/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:40:44 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/17 11:48:30 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	a;

	if (!lst)
		return (0);
	a = 1;
	while (lst->next)
	{
		lst = lst->next;
		a++;
	}	
	return (a);
}
