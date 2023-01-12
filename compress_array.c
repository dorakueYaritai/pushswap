/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:19:58 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/11 23:57:03 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		compress_list(int **list, int n);
static int	*dup_int_array(int *list, int n);
static void	exec_bubble_sort(int *array, int n);
static void	exec_compress(int **nsort, int *sort, int n);
static void	mini_swap(int *a, int *b);

void	compress_list(int **list, int n)
{
	int	*dup;

	dup = dup_int_array(*list, n);
	exec_bubble_sort(dup, n);
	exec_compress(list, dup, n);
	free (dup);
}

static int	*dup_int_array(int *list, int n)
{
	int	*dup;
	int	i;

	dup = malloc(sizeof(int) * n);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = list[i];
		++i;
	}
	return (dup);
}

static void	exec_bubble_sort(int *array, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (array[j] > array[j + 1])
				mini_swap(&array[j], &array[j + 1]);
			++j;
		}
		++i;
	}
}

void	exec_compress(int **nsort, int *sort, int n)
{
	int	*buf;
	int	i;
	int	j;

	buf = malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		j = 0;
		while ((*nsort)[i] != sort[j])
			j++;
		buf[i] = j;
		i++;
	}
	free (*nsort);
	*nsort = buf;
}

static void	mini_swap(int *a, int *b)
{
	const int	c = *b;

	*b = *a;
	*a = c;
}
