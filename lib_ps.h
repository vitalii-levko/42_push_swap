/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ps.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:13:57 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/08 16:25:13 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PS_H
# define LIB_PS_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include "libft/includes/ft_printf.h"
# include "libft/includes/get_next_line.h"
# define BF_SIZE 3

typedef struct	s_list
{
	long long int	nbr;
	struct s_list	*next;
}				t_list;

typedef struct	s_doop
{
	int		rr[2];
	int		s[2];
	int		r[2];
	int		p[2];
}				t_doop;

typedef struct	s_iter
{
	int		i;
	int		j;
	int		neg;
}				t_iter;

int				say(char *s);

int				err(void);

t_list			*ft_lstnew(long long int nbr);

void			ft_lstadd(t_list **head, long long int nbr);

void			ft_lstfree(t_list **lst);

void			ft_lstsfree(t_list **lst1, t_list **lst2);

void			push(t_list **head, t_list **lst);

void			swap(t_list *a, t_list *b);

void			rotate(t_list **a, t_list **b);

void			reverse(t_list **a, t_list **b);

int				buff_check_exec(t_list **a, t_list **b, char *str);

void			exec(t_list **a, char *str);

int				is_sort(t_list *a, t_list *b);

void			try_sort(t_list **a, t_list *b, long long int len);

t_list			*try_a_more(t_list **a, t_list **b, t_list **cnt,
							long long int *len);

long long int	try_b_case1(t_list **a, t_list **b, t_list *cnt, t_list **n);

void			try_a_case4(t_list **a, t_list **b, t_list **n);

void			try_a_case3(t_list **a, t_list **b, t_list **n);

void			try_a_case2(t_list **a, t_list **b);

void			try_a_case1(t_list **a, t_list **b, t_list **n);

void			a_three(t_list **a, t_list **b, t_list *cnt, t_list **n);

void			a_two(t_list **a, t_list **b, t_list *cnt, t_list **n);

void			do_sort(t_list **a, t_list **b, t_iter *it, t_doop *op);

void			sort_b(t_list *a, t_list *b, t_list *n, t_doop *op);

void			sort_a(t_list *a, t_list *n, t_iter *it, t_doop *op);

t_list			*get_last_elem(t_list *lst);

void			let_push(char *msg, t_list **head, t_list **lst);

void			let_swap(char *msg, t_list *a, t_list *b);

void			let_rotate(char *msg, t_list **a, t_list **b);

void			let_reverse(char *msg, t_list **a, t_list **b);

void			let_rsrs(char *msg, t_list **a, t_list **b);

void			merge_a(t_list **a, t_list **b, t_list *n,
						long long int lmh[3]);

void			merge_rot_a(t_list **a, long long int *inc);

void			merge_rot_a_next(t_list **a, t_list **n, long long int *inc);

void			merge_sw_rot_a(t_list **a, t_list **n, long long int kij[3]);

void			merge_push_rot_a(t_list **a, t_list **b, long long int *inc);

long long int	merge_push_b_rot_a(t_list **a, t_list **b, t_list **n,
									long long int kij[3]);

void			merge_rev_b_push_rot_a(t_list **a, t_list **b,
									long long int *inc);

void			merge_rev_a(t_list **a, long long int kij[3]);

long long int	get_med(t_list *a, long long int len);

t_list			*ft_lstcpy(t_list *a, long long int len);

void			sort(t_list **a, t_list *b, long long int len,
					long long int sz);

int				is_same(t_list *a);

int				is_lld(t_list *a);

#endif
