/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_let_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:13:57 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:47:45 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

void	let_push(char *msg, t_list **head, t_list **lst)
{
	say(msg);
	push(head, lst);
}

void	let_swap(char *msg, t_list *a, t_list *b)
{
	say(msg);
	swap(a, b);
}

void	let_rotate(char *msg, t_list **a, t_list **b)
{
	say(msg);
	rotate(a, b);
}

void	let_reverse(char *msg, t_list **a, t_list **b)
{
	say(msg);
	reverse(a, b);
}

void	let_rsrs(char *msg, t_list **a, t_list **b)
{
	t_list **tmp;

	say(msg);
	if (a && b)
	{
		rotate(a, b);
		swap(*a, *b);
		reverse(a, b);
		swap(*a, *b);
		return ;
	}
	else if (a)
		tmp = a;
	else
		tmp = b;
	rotate(tmp, NULL);
	swap(*tmp, NULL);
	reverse(tmp, NULL);
	swap(*tmp, NULL);
}
