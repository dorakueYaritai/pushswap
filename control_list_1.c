/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_list_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:01:28 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/11 23:38:57 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	pa(t_dlist **a, t_dlist **b)
{
	ft_printf("pa\n");
	push(b, a);
	return (0);
}

int	pb(t_dlist **a, t_dlist **b)
{
	ft_printf("pb\n");
	push(a, b);
	return (0);
}

int	sa(t_dlist **a)
{
	ft_printf("sa\n");
	swap(a);
	return (0);
}

int	sb(t_dlist **b)
{
	ft_printf("sb\n");
	swap(b);
	return (0);
}

int	ra(t_dlist **a)
{
	ft_printf("ra\n");
	rotate(a);
	return (0);
}
