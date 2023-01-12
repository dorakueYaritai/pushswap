/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_list_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:02:02 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/11 23:47:03 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rb(t_dlist **b)
{
	ft_printf("rb\n");
	rotate(b);
	return (0);
}

int	rra(t_dlist **a)
{
	ft_printf("rra\n");
	r_rotate(a);
	return (0);
}

int	rrb(t_dlist **b)
{
	ft_printf("rrb\n");
	r_rotate(b);
	return (0);
}

int	push(t_dlist **push, t_dlist **passive)
{
	t_dlist	*ndptr;

	if (*push == NULL)
		return (1);
	ndptr = (*push)->next;
	if (ndptr)
		ndptr -> prev = NULL;
	ft_dlstadd_front(passive, *push);
	*push = ndptr;
	return (0);
}

int	swap(t_dlist **ndptr_1)
{
	t_dlist	*ndptr_2;
	t_dlist	*ndptr_3;

	if (!ndptr_1)
		return (ERROR);
	if (!*ndptr_1)
		return (ERROR);
	if ((*ndptr_1)->next == NULL)
		return (ERROR);
	ndptr_2 = (*ndptr_1)->next;
	ndptr_3 = ndptr_2->next;
	(*ndptr_1)->prev = (*ndptr_1)->next;
	(*ndptr_1)->next = ndptr_2->next;
	ndptr_2->prev = NULL;
	ndptr_2->next = *ndptr_1;
	if (ndptr_3)
		ndptr_3->prev = *ndptr_1;
	*ndptr_1 = ndptr_2;
	return (0);
}
