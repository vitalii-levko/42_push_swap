/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_try_a_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:13:57 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:47:59 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

static long long int	a_more_init(t_list **a, long long int len)
{
	t_list			*c;
	long long int	med;

	c = ft_lstcpy(*a, len);
	sort(&c, NULL, len, 1);
	med = get_med(c, len);
	ft_lstfree(&c);
	return (med);
}

static void				a_decrement(long long int *len)
{
	*len -= 1;
}

static void				a_more(t_list **a, t_list **b, t_list **m, t_list **n)
{
	(*n) = (*n)->next;
	let_push("pb", b, a);
	(*m)->nbr += 1;
}

static void				a_less(t_list **a, t_list **n, long long int mst[3])
{
	*n = (*n)->next;
	let_rotate("ra", a, NULL);
	mst[1] += 1;
}

t_list					*try_a_more(t_list **a, t_list **b, t_list **cnt,
									long long int *len)
{
	t_list					*m;
	t_list					*n;
	long long int			mst[3];
	static long long int	init = 1;

	n = NULL;
	while (*len > 3)
	{
		mst[0] = a_more_init(a, *len);
		mst[1] = 0;
		mst[2] = *len;
		n = *a;
		ft_lstadd(cnt, 0);
		m = get_last_elem(*cnt);
		while (mst[2]-- > 0)
		{
			(n->nbr < mst[0]) ? (a_decrement(len)) : (NULL);
			(n->nbr < mst[0]) ? (a_more(a, b, &m, &n)) : (a_less(a, &n, mst));
		}
		if (init != 1)
			while (mst[1]-- > 0)
				let_reverse("rra", a, NULL);
	}
	init++;
	return (n);
}
