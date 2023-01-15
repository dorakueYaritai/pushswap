/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakiba <kotto555555@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:04:33 by kakiba            #+#    #+#             */
/*   Updated: 2023/01/15 10:48:22 by kakiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include "libft.h"
# include <errno.h>

# define ERROR 1

void	exit_error(t_dlist **list, void *a, void *b, char *error_text);

/* ---- check_error.c ---- */
int		check_error(int argc, char *argv[], int *list);

/* ---- compress_array.c ---- */
void	compress_list(int **list, int n);

/* ---- init.c ---- */
int		init_dlist_free_list(t_dlist **a, int n, int *list);

/* ---- utils.c ---- */
t_dlist	*ft_dlstlast_nfinish(t_dlist *lst);
size_t	dlist_nset_size(t_dlist *lst);
int		issort(t_dlist *a);
int		abs(int x);

/* ---- print_dlist.c ---- */
int		print_dlist(t_dlist *a, t_dlist *b);

/* ---- control_list.c ---- */
int		push(t_dlist **push, t_dlist **passive);
int		swap(t_dlist **ndptr_1);
int		rotate(t_dlist **top);
int		r_rotate(t_dlist **top);
int		sa(t_dlist **a);
int		sb(t_dlist **b);
int		ss(t_dlist **a, t_dlist **b);
int		pa(t_dlist **a, t_dlist **b);
int		pb(t_dlist **a, t_dlist **b);
int		ra(t_dlist **a);
int		rb(t_dlist **b);
int		rr(t_dlist **a, t_dlist **b);
int		rra(t_dlist **a);
int		rrb(t_dlist **b);
int		rrr(t_dlist **a, t_dlist **b);

/* ---- sort_radix.c ---- */
int		radix_sort(t_dlist **a, t_dlist **b, int size);

/* ---- sort_quick.c ---- */
int		b_sort(t_dlist **a, t_dlist **b);
void	bsort_two(t_dlist **list);
int		sort(t_dlist **a, t_dlist **b);
void	sort_two(t_dlist **list);

/* ---- sort_insertion.c ---- */
void	sort_insertion(t_dlist **a, t_dlist **b, int size);

/* ---- sort_ministack.c ---- */
void	sort_ministack(t_dlist **a, t_dlist **b, int size);
void	pb_min_of_a(t_dlist **a, t_dlist **b, int size);

#endif