/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:13:57 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:47:56 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

static int	is_part_sort_b(t_list *b, long long int init)
{
	t_list			*n;
	long long int	i;

	while (b && b->next)
	{
		n = b->next;
		i = 1;
		while (n && i < init)
		{
			b = b->next;
			n = n->next;
			i++;
		}
		if (i == init && n && n->nbr > b->nbr)
			return (1);
		i = 1;
		while (n && i < init)
		{
			n = n->next;
			i++;
		}
		if (n)
			b = n->next;
	}
	return (0);
}

static int	is_part_sort_a(t_list *a, long long int init)
{
	t_list			*n;
	long long int	i;

	while (a && a->next)
	{
		n = a->next;
		i = 1;
		while (n && i < init)
		{
			a = a->next;
			n = n->next;
			i++;
		}
		if (i == init && n && n->nbr < a->nbr)
			return (1);
		i = 1;
		while (n && i < init)
		{
			n = n->next;
			i++;
		}
		if (n)
			a = n->next;
	}
	return (0);
}

void		sort(t_list **a, t_list *b, long long int len, long long int sz)
{
	long long int	lmh[3];

	while (sz < len && (is_sort(*a, NULL) != 0 || b != NULL))
	{
		if (b || is_part_sort_a(*a, sz) != 0 || is_part_sort_b(b, sz) != 0)
		{
			lmh[0] = 0;
			while (lmh[0] < len - sz &&
				(is_sort(*a, b) != 0 || b != NULL))
			{
				lmh[1] = lmh[0] + sz - 1;
				lmh[2] = ((lmh[0] + sz + sz - 1 < len - 1) ?
						(lmh[0] + sz + sz - 1) : (len - 1));
				merge_a(a, &b, *a, lmh);
				lmh[0] += sz + sz;
			}
			if (lmh[0] < len && is_sort(*a, NULL) != 0)
			{
				lmh[0] = len - lmh[0];
				while (lmh[0]-- > 0)
					rotate(a, NULL);
			}
		}
		sz = sz + sz;
	}
}
