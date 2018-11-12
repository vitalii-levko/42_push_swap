/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:13:57 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:48:39 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

void			merge_rev_b_push_rot_a(t_list **a, t_list **b,
									long long int *inc)
{
	reverse(NULL, b);
	push(a, b);
	rotate(a, NULL);
	*inc += 1;
}

void			merge_rev_a(t_list **a, long long int kij[3])
{
	reverse(a, NULL);
	kij[2]++;
}

t_list			*get_last_elem(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

long long int	get_med(t_list *a, long long int len)
{
	long long int	med;
	long long int	i;
	t_list			*n;

	med = 0;
	n = a;
	i = 0;
	while (i < len / 2)
	{
		n = n->next;
		i++;
	}
	med = n->nbr;
	return (med);
}

t_list			*ft_lstcpy(t_list *a, long long int len)
{
	t_list	*c;
	t_list	*n;

	c = NULL;
	n = a;
	while (n && len > 0)
	{
		ft_lstadd(&c, n->nbr);
		n = n->next;
		len--;
	}
	return (c);
}
