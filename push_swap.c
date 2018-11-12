/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:28:27 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:48:44 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

static int	check_argv(char **av, t_list **a, t_iter *it)
{
	av++;
	while (*av)
	{
		it->i = 0;
		it->neg = 0;
		while ((*av)[it->i])
		{
			if ((*av)[it->i] == '-' && it->neg != 1)
			{
				it->i += 1;
				it->neg = 1;
			}
			else if ((*av)[it->i] == '-')
				return (say("Error"));
			if (ft_isdigit((*av)[it->i]) == 0)
				return (say("Error"));
			if (it->neg == 0)
				it->neg = 1;
			it->i += 1;
		}
		ft_lstadd(a, ft_atoi(*av));
		av++;
	}
	return (0);
}

static int	free_all(t_list **a, t_list **b, t_iter **it, t_doop **op)
{
	if (a && *a)
		ft_lstfree(a);
	if (b && *b)
		ft_lstfree(b);
	if (it && *it)
	{
		free(*it);
		it = NULL;
	}
	if (op && *op)
	{
		free(*op);
		op = NULL;
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_list *a;
	t_list *b;
	t_iter *it;
	t_doop *op;

	a = NULL;
	b = NULL;
	if (!(it = (t_iter *)malloc(sizeof(t_iter))) ||
		!(op = (t_doop *)malloc(sizeof(t_doop))))
		return (free_all(&a, NULL, &it, &op));
	if (ac != 1)
	{
		if (check_argv(av, &a, it) == 1)
			return (free_all(&a, NULL, &it, &op));
		if (is_same(a) || is_lld(a))
			return (free_all(&a, NULL, &it, &op));
		while ((it->i = is_sort(a, NULL)) != 0 || b != NULL)
			if (ac - 1 > 5)
				try_sort(&a, NULL, ac - 1);
			else
				do_sort(&a, &b, it, op);
	}
	return (0);
}
