/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_merge_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:13:57 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:47:48 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

static void	merge_a_init(long long int kij[3], long long int lmh[3])
{
	kij[0] = lmh[0];
	kij[1] = lmh[0];
	kij[2] = lmh[1] + 1;
}

static void	merge_a_three(t_list **a, t_list **b, t_list **n,
							long long int kij[3])
{
	if ((*a)->next == *n)
		merge_sw_rot_a(a, n, kij);
	else if ((*n)->next)
		merge_push_b_rot_a(a, b, n, kij);
	else
		merge_rev_a(a, kij);
}

static void	merge_a_two(t_list **a, t_list *n, long long int kij[3],
						long long int lmh[3])
{
	if (kij[1] > lmh[1])
		merge_rot_a(a, &(kij[2]));
	else if (kij[2] > lmh[2] || (*a)->nbr < n->nbr)
		merge_rot_a(a, &(kij[1]));
}

static void	merge_a_one(t_list **a, t_list **b, long long int kij[3])
{
	if ((*b)->next == NULL || (*b)->next->next == NULL)
		merge_push_rot_a(a, b, &(kij[1]));
	else
		merge_rev_b_push_rot_a(a, b, &(kij[1]));
}

void		merge_a(t_list **a, t_list **b, t_list *n, long long int lmh[3])
{
	long long int	kij[3];
	t_list			*m;

	kij[0] = lmh[0];
	while (kij[0]++ <= lmh[1])
		n = n->next;
	merge_a_init(kij, lmh);
	while (kij[0] <= lmh[2] && (is_sort(*a, NULL) != 0 || *b != NULL))
	{
		if (*b != NULL)
		{
			m = get_last_elem(*b);
			if (kij[2] > lmh[2])
				merge_push_rot_a(a, b, &(kij[1]));
			else if (m->nbr > n->nbr)
				merge_rot_a_next(a, &n, &(kij[2]));
			else
				merge_a_one(a, b, kij);
		}
		else if (kij[1] > lmh[1] || kij[2] > lmh[2] || (*a)->nbr < n->nbr)
			merge_a_two(a, n, kij, lmh);
		else
			merge_a_three(a, b, &n, kij);
		kij[0]++;
	}
}
