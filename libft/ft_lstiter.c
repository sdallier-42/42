/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:38:19 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/17 12:42:29 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst)
	{
		current = lst;
		while (current)
		{
			next = current->next;
			(*f)(current->content);
			current = next;
		}
		lst = NULL;
	}
}
