/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_nset_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 21:03:14 by kakiba            #+#    #+#             */
/*   Updated: 2022/12/30 21:03:41 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	dlist_set_size(t_dlist *lst)
{
	size_t	set;

	set = 0;
	while (lst)
	{
		if (lst -> i_done == 1)
			++set;
		lst = lst -> next;
	}
	return (set);
}
