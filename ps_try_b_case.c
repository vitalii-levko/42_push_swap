/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_try_b_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:13:57 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:48:03 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

static void				try_b_case4(t_list **b, t_list **cnt, t_list **n,
									t_list **m)
{
	long long int	tmp;

	if ((*cnt)->next && (*m)->nbr > 0)
	{
		tmp = (*m)->nbr;
		while (tmp-- > 0)
			let_reverse("rrb", NULL, b);
	}
	else if ((*m)->nbr == 0)
	{
		*n = *cnt;
		if (*n != *m)
		{
			while ((*n)->next && (*n)->next != *m)
				*n = (*n)->next;
			(*n)->next = NULL;
			ft_lstfree(m);
		}
		else
			ft_lstfree(cnt);
	}
}

static long long int	try_b_case3(t_list **a, t_list **b, t_list *m,
									t_list **n)
{
	t_list			*c;
	long long int	med_len[2];
	long long int	tmp;

	med_len[1] = 0;
	c = ft_lstcpy(*b, m->nbr);
	sort(&c, NULL, m->nbr, 1);
	med_len[0] = get_med(c, m->nbr);
	ft_lstfree(&c);
	*n = *b;
	tmp = m->nbr;
	while (tmp-- > 0)
	{
		if ((*n)->nbr >= med_len[0])
		{
			*n = (*n)->next;
			let_push("pa", a, b);
			m->nbr -= 1;
			med_len[1] += 1;
			continue ;
		}
		*n = (*n)->next;
		let_rotate("rb", NULL, b);
	}
	return (med_len[1]);
}

static long long int	try_b_case2(t_list **a, t_list **b, t_list *cnt,
									t_list **n)
{
	t_list			*m;
	long long int	len;

	m = get_last_elem(cnt);
	len = try_b_case3(a, b, m, n);
	try_b_case4(b, &cnt, n, &m);
	return (len);
}

long long int			try_b_case1(t_list **a, t_list **b, t_list *cnt,
									t_list **n)
{
	t_list			*m;
	long long int	len;

	m = get_last_elem(cnt);
	if (m->nbr > 3)
		return (try_b_case2(a, b, cnt, n));
	len = m->nbr;
	while (m->nbr > 0)
	{
		let_push("pa", a, b);
		m->nbr -= 1;
	}
	*n = cnt;
	if (*n != m)
	{
		while ((*n)->next && (*n)->next != m)
			*n = (*n)->next;
		(*n)->next = NULL;
		ft_lstfree(&m);
	}
	else
		ft_lstfree(&cnt);
	return (len);
}
