/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_merge_a_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:13:57 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:47:51 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

void			merge_rot_a(t_list **a, long long int *inc)
{
	rotate(a, NULL);
	*inc += 1;
}

void			merge_rot_a_next(t_list **a, t_list **n, long long int *inc)
{
	*n = (*n)->next;
	rotate(a, NULL);
	*inc += 1;
}

void			merge_sw_rot_a(t_list **a, t_list **n, long long int kij[3])
{
	*n = (*n)->next;
	swap(*a, NULL);
	if (is_sort(*a, NULL) != 0)
	{
		rotate(a, NULL);
		kij[2]++;
	}
}

void			merge_push_rot_a(t_list **a, t_list **b, long long int *inc)
{
	while (*b != NULL)
		push(a, b);
	rotate(a, NULL);
	*inc += 1;
}

long long int	merge_push_b_rot_a(t_list **a, t_list **b, t_list **n,
									long long int kij[3])
{
	long long int	lo;

	lo = 0;
	while (*a != *n)
	{
		push(b, a);
		lo++;
	}
	*n = (*n)->next;
	rotate(a, NULL);
	kij[2]++;
	return (lo);
}
