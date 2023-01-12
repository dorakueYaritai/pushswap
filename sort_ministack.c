/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ministack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:29:52 by kakiba            #+#    #+#             */
/*   Updated: 2022/12/30 20:31:53 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	judge_swap_stack(t_dlist **list, char name);
void	sort_three_stack_a(t_dlist **a);
void	sort_three_stack_b(t_dlist **a);
void	sort_four_five_stack(t_dlist **a, t_dlist **b, int size);

void	sort_ministack(t_dlist **a, t_dlist **b, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
		judge_swap_stack(a, 'a');
	else if (size == 3)
		sort_three_stack_a(a);
	else
		sort_four_five_stack(a, b, size);
}

void	judge_swap_stack(t_dlist **list, char name)
{
	const int	first = (*list)->content;
	const int	second = (*list)->next->content;

	if (first > second && name == 'a')
		sa(list);
	if (first < second && name == 'b')
		sb(list);
}

void	sort_three_stack_a(t_dlist **a)
{
	const int	first = (*a)->content;
	const int	second = (*a)->next->content;
	const int	last = ft_dlstlast_nfinish(*a)->content;

	while (issort(*a) == 0)
	{
		if (first > second && second > last)
		{
			sa(a);
			rra(a);
		}
		else if (first > last && last > second)
			ra(a);
		else if (last > first && first > second)
			sa(a);
		else if (second > last && last > first)
		{
			rra(a);
			sa(a);
		}
		else
			rra(a);
	}
}

void	pb_min_of_a(t_dlist **a, t_dlist **b, int size)
{
	t_dlist	*nd;
	int		min;
	int		distance;

	min = 0;
	nd = NULL;
	distance = 0;
	while (min < size && nd == NULL)
	{
		nd = dlist_search_content(*a, min, &distance);
		if (nd == NULL)
		{
			distance = 0;
			++min;
		}
	}
	if (!nd)
		return ;
	if (distance <= size / 2)
		while ((*a) != nd)
			ra(a);
	else
		while ((*a) != nd)
			rra(a);
	pb(a, b);
}

void	sort_four_five_stack(t_dlist **a, t_dlist **b, int size)
{
	int	pb_count;

	pb_count = 0;
	while (size - pb_count > 3)
	{
		pb_min_of_a(a, b, size);
		++pb_count;
	}
	sort_three_stack_a(a);
	if (pb_count == 2)
		judge_swap_stack(b, 'b');
	while (pb_count--)
		pa(a, b);
}
