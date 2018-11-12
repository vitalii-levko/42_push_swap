/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_try_do_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:13:57 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:48:15 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

void	a_three(t_list **a, t_list **b, t_list *cnt, t_list **n)
{
	t_list	*m;

	m = cnt;
	while (m && m->next)
		m = m->next;
	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr < (*a)->next->next->nbr)
		(*b && (*n)->next && (*b)->nbr < (*b)->next->nbr) ?
		let_swap("ss", *a, *b) : let_swap("sa", *a, NULL);
	else if (((*a)->nbr < (*a)->next->nbr) &&
			((*a)->next->next->nbr < (*a)->nbr))
		try_a_case1(a, b, n);
	else if ((*a)->nbr > (*a)->next->nbr &&
			(*a)->next->nbr > (*a)->next->next->nbr)
		try_a_case2(a, b);
	else if ((*a)->nbr > (*a)->next->next->nbr &&
			(*a)->next->nbr < (*a)->next->next->nbr)
		try_a_case3(a, b, n);
	else if ((*a)->nbr < (*a)->next->next->nbr &&
			(*a)->next->next->nbr < (*a)->next->nbr)
		try_a_case4(a, b, n);
}

void	a_two(t_list **a, t_list **b, t_list *cnt, t_list **n)
{
	t_list	*m;

	m = cnt;
	while (m && m->next)
		m = m->next;
	(*b && (*n)->next && (*b)->nbr < (*b)->next->nbr) ?
	let_swap("ss", *a, *b) : let_swap("sa", *a, NULL);
}

void	sort_a(t_list *a, t_list *n, t_iter *it, t_doop *op)
{
	if (a->nbr > a->next->nbr)
	{
		if (a->next->nbr > n->nbr)
			op->r[0] = 1;
		else if (a->nbr > n->nbr)
		{
			if (a->next->next && a->next->next->nbr > a->next->nbr &&
				a->next->next->nbr > a->nbr)
				op->s[0] = 1;
			else
				op->r[0] = 1;
		}
		else
			op->s[0] = 1;
		return ;
	}
	if (a->nbr > n->nbr)
		op->rr[0] = 1;
	else if (it->i != 0 && a->next->nbr > n->nbr)
	{
		op->rr[0] = 1;
		op->s[0] = 1;
	}
	else if (it->i != 0)
		op->p[0] = 1;
}

void	sort_b(t_list *a, t_list *b, t_list *n, t_doop *op)
{
	if (b->nbr < b->next->nbr)
	{
		if (b->next->nbr < n->nbr)
			op->r[1] = 1;
		else if (b->nbr < n->nbr)
		{
			if (b->next->next && b->next->next->nbr < b->next->nbr &&
				b->next->next->nbr < b->nbr)
				op->s[1] = 1;
			else
				op->r[1] = 1;
		}
		else
			op->s[1] = 1;
		return ;
	}
	if (b->nbr < n->nbr)
		op->rr[1] = 1;
	else if (is_sort(NULL, b) != 0 && b->next->nbr < n->nbr)
	{
		op->rr[1] = 1;
		op->s[1] = 1;
	}
	else if (is_sort(a, NULL) == 0)
		op->p[1] = 1;
}
