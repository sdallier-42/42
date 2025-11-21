/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdallier <sdallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:12:02 by sdallier          #+#    #+#             */
/*   Updated: 2025/11/20 12:16:47 by sdallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	r;
	int	r2;
	
	r = ft_printf(" %p %p ", 0, 0);
	write(1, "\n", 1);
	printf("size = %d\n", r);

	// r2 = printf (" %p %p ", 0, 0);
	// write(1, "\n", 1);
	// printf("size2 = %d\n", r2);
	// return (0);
}
