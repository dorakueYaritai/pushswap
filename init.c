/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:40:02 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/15 15:15:19 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	init_dlist_free_list(t_dlist **a, int n, int *list)
{
	int		i;
	t_dlist	*nd;

	i = 0;
	while (i < n)
	{
		nd = ft_dlstnew(list[i]);
		if (!nd)
			exit_error(a, list, NULL, "ERROR");
		ft_dlstadd_back(a, nd);
		++i;
	}
	free (list);
	return (0);
}
