/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:29:51 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/01 08:20:32 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char *argv[])
{
	t_dlist		*a;
	t_dlist		*b;
	int			*list;
	const int	size = argc - 1;

	a = NULL;
	b = NULL;
	list = malloc(sizeof(int) * size);
	if (check_error(argc, argv, list) == ERROR)
		return (ERROR);
	compress_list(&list, size);
	if (init_dlist_free_list(&a, size, list) == ERROR)
		return (ERROR);
	if (issort(a) == 0)
	{
		if (size <= 5)
			sort_ministack(&a, &b, size);
		else
			radix_sort(&a, &b, size);
	}
	if (a)
		ft_dlstclear(&a, NULL);
	if (b)
		ft_dlstclear(&b, NULL);
	return (0);
}
