/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:26:37 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/11 23:01:48 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			check_error(int argc, char *argv[], int *list);
static int	check_error_dup(int argc, int *list);
static int	check_error_strtol(int argc, char *argv[], int *list);
static int	x_check_is_disit_arg(char *argv[], int i, int j, int *list);

int	check_error(int argc, char *argv[], int *list)
{
	size_t	i;
	size_t	j;

	if (!list)
		return (ERROR);
	if (argc == 1)
	{
		free (list);
		return (ERROR);
	}
	i = 1;
	while (i < (size_t)argc)
	{
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (x_check_is_disit_arg(argv, i, j, list) == ERROR)
				return (ERROR);
			j++;
		}
		++i;
	}
	return (check_error_strtol(argc, argv, list));
}

static int	x_check_is_disit_arg(char *argv[], int i, int j, int *list)
{
	if (ft_isdigit(argv[i][j]) == 0 && \
		!(j == 0 && (argv[i][j] == '-' || argv[i][j] == '+') && \
		('1' <= argv[i][j + 1] && argv[i][j + 1] <= '9')))
	{
		write(2, "ERROR\n", 7);
		free (list);
		return (ERROR);
	}
	return (0);
}

static int	check_error_strtol(int argc, char *argv[], int *list)
{
	long	buf;
	size_t	i;

	i = 1;
	while (i < (size_t)argc)
	{
		buf = ft_strtol(argv[i], NULL, 10);
		if (buf > INT_MAX || buf < INT_MIN)
		{
			write(2, "ERROR\n", 7);
			free (list);
			return (1);
		}
		else
			list[i - 1] = (int)buf;
		++i;
	}
	return (check_error_dup(argc, list));
}

static int	check_error_dup(int argc, int *list)
{
	size_t	i;
	size_t	j;
	int		target;

	i = 0;
	while (i + 1 < (size_t)argc)
	{
		target = list[i];
		j = i + 1;
		while (j + 1 < (size_t)argc)
		{
			if (target == list[j++])
			{
				write(2, "ERROR\n", 7);
				free (list);
				return (ERROR);
			}
		}
		++i;
	}
	return (0);
}
