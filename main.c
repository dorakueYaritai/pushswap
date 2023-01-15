/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:29:51 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/15 10:57:27 by kakiba           ###   ########.fr       */
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
	list = malloc(sizeof(int) * (size));
	check_error(argc, argv, list);
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

void	exit_error(t_dlist **list, void *a, void *b, char *error_text)
{
	if (error_text)
		write(STDERR_FILENO, error_text, ft_strlen(error_text));
	if (list)
		ft_dlstclear(list, NULL);
	if (a)
		ft_dlstdelone(a, NULL);
	if (b)
		ft_dlstdelone(b, NULL);
	exit(EXIT_FAILURE);
}
