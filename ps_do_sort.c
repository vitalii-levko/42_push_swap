/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:13:57 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:47:42 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

static void	do_rrr(t_list **a, t_list **b, t_doop *op)
{
	if (op->rr[0] && op->rr[1])
	{
		say("rrr");
		reverse(a, b);
	}
	else if (op->rr[0])
	{
		say("rra");
		reverse(a, NULL);
	}
	else if (op->rr[1])
	{
		say("rrb");
		reverse(NULL, b);
	}
}

static void	do_ss(t_list **a, t_list **b, t_doop *op)
{
	if (op->s[0] && op->s[1])
	{
		say("ss");
		swap(*a, *b);
	}
	else if (op->s[0])
	{
		say("sa");
		swap(*a, NULL);
	}
	else if (op->s[1])
	{
		say("sb");
		swap(NULL, *b);
	}
}

static void	do_rr(t_list **a, t_list **b, t_doop *op)
{
	if (op->r[0] && op->r[1])
	{
		say("rr");
		rotate(a, b);
	}
	else if (op->r[0])
	{
		say("ra");
		rotate(a, NULL);
	}
	else if (op->r[1])
	{
		say("rb");
		rotate(NULL, b);
	}
}

static void	do_op(t_list **a, t_list **b, t_doop *op)
{
	do_rrr(a, b, op);
	do_ss(a, b, op);
	do_rr(a, b, op);
	if (op->p[0])
		let_push("pb", b, a);
	if (op->p[1])
		let_push("pa", a, b);
}

void		do_sort(t_list **a, t_list **b, t_iter *it, t_doop *op)
{
	it->j = 0;
	while (it->j < 2)
	{
		op->rr[it->j] = 0;
		op->s[it->j] = 0;
		op->r[it->j] = 0;
		op->p[it->j] = 0;
		it->j += 1;
	}
	if (*a && (*a)->next)
		sort_a(*a, get_last_elem(*a), it, op);
	if (*b && (*b)->next)
		sort_b(*a, *b, get_last_elem(*b), op);
	else if (is_sort(*a, NULL) == 0)
		op->p[1] = 1;
	do_op(a, b, op);
}
