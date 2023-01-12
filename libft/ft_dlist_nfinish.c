/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_nfinish.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 21:03:54 by kakiba            #+#    #+#             */
/*   Updated: 2022/12/31 10:15:28 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
