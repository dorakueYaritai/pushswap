/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:40:02 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/11 18:30:59 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	init_dlist_free_list(t_dlist **a, int n, int *list)
{
	int	i;

	i = 0;
	while (i < n)
		ft_dlstadd_back(a, ft_dlstnew(list[i++]));
	free (list);
	return (0);
}
