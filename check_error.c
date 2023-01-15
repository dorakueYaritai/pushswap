/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:26:37 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/15 11:02:24 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			check_error(int argc, char *argv[], int *list);
static int	check_error_dup(int argc, int *list);
static int	check_error_strtol(int argc, char *argv[], int *list);
static int	x_check_is_disit_arg(char *argv[], int i, int j, int *list);

int	check_error(int argc, char *argv[], int *list)
{
	int		i;
	size_t	j;
	size_t	len;

	if (!list)
		exit_error(NULL, NULL, NULL, "ERROR");
	if (argc == 1)
		exit_error(NULL, list, NULL, NULL);
	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i] == NULL)
			exit_error(NULL, list, NULL, "ERROR");
		len = ft_strlen(argv[i]);
		while (j < len)
		{
			x_check_is_disit_arg(argv, i, j, list);
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
		exit_error(NULL, list, NULL, "ERROR");
	}
	return (0);
}

static int	check_error_strtol(int argc, char *argv[], int *list)
{
	long	buf;
	int		i;

	i = 1;
	while (i < argc)
	{
		buf = ft_strtol(argv[i], NULL, 10);
		if (buf > INT_MAX || buf < INT_MIN)
			exit_error(NULL, list, NULL, "ERROR");
		else
			list[i - 1] = (int)buf;
		++i;
	}
	return (check_error_dup(argc, list));
}

static int	check_error_dup(int argc, int *list)
{
	int			i;
	int			j;
	int			target;
	const int	list_size = argc - 1;

	i = 0;
	while (i < list_size)
	{
		target = list[i];
		j = i + 1;
		while (j < list_size)
		{
			if (target == list[j++])
				exit_error(NULL, list, NULL, "ERROR");
		}
		++i;
	}
	return (0);
}
