/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:46:55 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/11 18:33:52 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	void	x_print(t_dlist **ndptr_a, t_dlist \
**ndptr_b, int *flag1, int *flag2);

int	print_dlist(t_dlist *a, t_dlist *b)
{
	t_dlist	*ndptr_a;
	t_dlist	*ndptr_b;
	int		flag1;
	int		flag2;

	flag1 = 1;
	flag2 = 1;
	ndptr_a = a;
	ndptr_b = b;
	ft_printf("-----------------\n");
	while (flag1 || flag2)
		x_print(&ndptr_a, &ndptr_b, &flag1, &flag2);
	ft_printf("-----------------\n");
	return (0);
}

static	void	x_print(t_dlist **ndptr_a, t_dlist
**ndptr_b, int *flag1, int *flag2)
{
	if ((*ndptr_a))
	{
		ft_printf("a: %d,  times: %d  done: %d   ", (*ndptr_a)->content, \
		(*ndptr_a)->times, (*ndptr_a)->i_done);
		(*ndptr_a) = (*ndptr_a)->next;
	}
	else
	{
		ft_printf("                           ");
		*flag1 = 0;
	}
	if ((*ndptr_b))
	{
		ft_printf("b: %d:  times: %d, done: %d", (*ndptr_b)->content, \
		(*ndptr_b)->times, (*ndptr_b)->i_done);
		(*ndptr_b) = (*ndptr_b)->next;
	}
	else
		*flag2 = 0;
	ft_printf("\n");
}
