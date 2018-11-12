/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:13:57 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/08 16:21:59 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

int				err(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int				is_same(t_list *a)
{
	long long int	curr;
	t_list			*n;

	while (a)
	{
		n = a->next;
		curr = a->nbr;
		while (n)
		{
			if (n->nbr == curr)
				return (err());
			n = n->next;
		}
		a = a->next;
	}
	return (0);
}

int				is_lld(t_list *a)
{
	while (a)
	{
		if (a->nbr > INT_MAX || a->nbr < INT_MIN)
			return (err());
		a = a->next;
	}
	return (0);
}
