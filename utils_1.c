/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:58:04 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/15 21:15:33 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	issort(t_dlist *a)
{
	while (a->next)
	{
		if (a ->content > a->next->content)
			return (0);
		a = a -> next;
	}
	return (1);
}

t_dlist	*ft_dlstlast_nfinish(t_dlist *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
	{
		if (lst -> next -> i_done == 1)
			break ;
		lst = lst -> next;
	}
	return (lst);
}

size_t	dlist_nset_size(t_dlist *lst)
{
	size_t	nset;

	nset = 0;
	while (lst)
	{
		if (lst -> i_done == 0)
			++nset;
		lst = lst -> next;
	}
	return (nset);
}

int	abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}
