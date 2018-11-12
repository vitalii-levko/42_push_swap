/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_try_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:13:57 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:48:36 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

void	try_a_case4(t_list **a, t_list **b, t_list **n)
{
	if (*b && (*b)->next && (*b)->next->next &&
		(*b)->nbr > (*b)->next->next->nbr &&
		(*b)->next->next->nbr > (*b)->next->nbr)
	{
		let_rotate("rr", a, b);
		let_swap("ss", *a, *b);
		let_reverse("rrr", a, b);
	}
	else
	{
		let_rotate("ra", a, NULL);
		(*b && *n && (*n)->next && (*b)->nbr < (*b)->next->nbr) ?
		let_swap("ss", *a, *b) : let_swap("sa", *a, NULL);
		let_reverse("rra", a, NULL);
	}
}

void	try_a_case3(t_list **a, t_list **b, t_list **n)
{
	if (*b && (*b)->next && (*b)->next->next &&
		((*b)->nbr < (*b)->next->next->nbr) &&
		(*b)->next->nbr > (*b)->next->next->nbr)
	{
		let_swap("ss", *a, *b);
		let_rotate("rr", a, b);
		let_swap("ss", *a, *b);
		let_reverse("rrr", a, b);
	}
	else
	{
		(*b && (*n)->next && (*b)->nbr < (*b)->next->nbr) ?
		let_swap("ss", *a, *b) : let_swap("sa", *a, NULL);
		let_rotate("ra", a, NULL);
		let_swap("sa", *a, NULL);
		let_reverse("rra", a, NULL);
	}
}

void	try_a_case2(t_list **a, t_list **b)
{
	if (*b && (*b)->next && (*b)->next->next && (*b)->nbr < (*b)->next->nbr
		&& (*b)->next->nbr < (*b)->next->next->nbr)
	{
		let_swap("ss", *a, *b);
		let_rsrs("rr\nss\nrrr\nss", a, b);
		return ;
	}
	else if (*b && (*b)->next && (*b)->next->next &&
			(*b)->nbr > (*b)->next->nbr && (*b)->next->next->nbr > (*b)->nbr)
	{
		let_swap("sa", *a, NULL);
		let_rsrs("rr\nss\nrrr\nss", a, b);
		return ;
	}
	(*b && (*b)->next && (*b)->nbr < (*b)->next->nbr) ?
	let_swap("ss", *a, *b) : let_swap("sa", *a, NULL);
	if (*b && (*b)->next && (*b)->next->next && (*b)->nbr > (*b)->next->nbr
		&& (*b)->next->next->nbr > (*b)->nbr)
		let_rsrs("rr\nss\nrrr\nss", a, b);
	else
		let_rsrs("ra\nsa\nrra\nsa", a, NULL);
}

void	try_a_case1(t_list **a, t_list **b, t_list **n)
{
	if (*b && (*b)->next && (*b)->next->next && (*b)->nbr > (*b)->next->nbr &&
		(*b)->next->next->nbr > (*b)->nbr)
		let_rsrs("rr\nss\nrrr\nss", a, b);
	else
	{
		let_rotate("ra", a, NULL);
		(*b && *n && (*n)->next && (*b)->nbr < (*b)->next->nbr) ?
		let_swap("ss", *a, *b) : let_swap("sa", *a, NULL);
		let_reverse("rra", a, NULL);
		let_swap("sa", *a, NULL);
	}
}

void	try_sort(t_list **a, t_list *b, long long int len)
{
	t_list			*n;
	t_list			*cnt;
	t_list			*tmp;

	n = NULL;
	cnt = NULL;
	while (is_sort(*a, NULL) != 0 || b != NULL)
	{
		if (cnt && cnt->nbr == 4 && cnt->next == NULL)
			;
		while (is_sort(*a, NULL) != 0)
		{
			if (len <= 3)
				(len == 2) ? a_two(a, &b, cnt, &n) : a_three(a, &b, cnt, &n);
			else
			{
				if ((tmp = try_a_more(a, &b, &cnt, &len)) != NULL)
					n = tmp;
			}
		}
		if (b != NULL)
			len = try_b_case1(a, &b, cnt, &n);
	}
}
