/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:55:19 by kakiba            #+#    #+#             */
/*   Updated: 2022/12/31 10:39:16 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	radix_sort(t_dlist **a, t_dlist **b, int size)
{
	int32_t	bit;
	int		i;

	bit = 0b01;
	while (bit <= size)
	{
		i = 0;
		while (i < size)
		{
			if ((bit & (*a)->content) == 0)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (*b)
		{
			pa(a, b);
			--i;
		}
		bit = bit << 1;
	}
	return (0);
}
