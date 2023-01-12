/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_search_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:48:58 by kakiba            #+#    #+#             */
/*   Updated: 2022/12/30 20:49:31 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*dlist_search_content(t_dlist *lst, int n, int *distance)
{
	while (lst)
	{
		if (lst -> content == n)
			return (lst);
		lst = lst -> next;
		(*distance) += 1;
	}
	return (NULL);
}
