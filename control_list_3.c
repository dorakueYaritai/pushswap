/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_list_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:02:50 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/04 07:08:41 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ss(t_dlist **a, t_dlist **b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
	return (0);
}

int	rotate(t_dlist **top)
{
	t_dlist	*second;
	t_dlist	*last;

	if (!top)
		return (ERROR);
	if (!*top)
		return (ERROR);
	second = (*top)->next;
	if (second == NULL)
		return (ERROR);
	last = ft_dlstlast(*top);
	(*top)->next = NULL;
	(*top)->prev = last;
	second->prev = NULL;
	last->next = *top;
	*top = second;
	return (0);
}

int	rr(t_dlist **a, t_dlist **b)
{
	ft_printf("rr");
	rotate(a);
	rotate(b);
	return (0);
}

int	r_rotate(t_dlist **top)
{
	t_dlist	*pre_last;
	t_dlist	*last;

	if (!top)
		return (ERROR);
	if (!*top)
		return (ERROR);
	last = ft_dlstlast(*top);
	pre_last = last->prev;
	if (pre_last == NULL)
		return (ERROR);
	(*top)->prev = last;
	pre_last->next = NULL;
	last->next = *top;
	last->prev = NULL;
	*top = last;
	return (0);
}

int	rrr(t_dlist **a, t_dlist **b)
{
	ft_printf("rrr");
	r_rotate(a);
	r_rotate(b);
	return (0);
}
