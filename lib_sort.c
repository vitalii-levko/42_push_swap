/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:18:00 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:46:05 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"
#include <stdio.h>

int		say(char *s)
{
	ft_printf("%s\n", s);
	return (1);
}

void	push(t_list **head, t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
	if (*lst == NULL)
		return ;
	if (*head)
	{
		tmp = *head;
		(*head) = ft_lstnew((*lst)->nbr);
		(*head)->next = tmp;
	}
	else
		*head = ft_lstnew((*lst)->nbr);
	tmp = *lst;
	*lst = (*lst)->next;
	free(tmp);
	tmp = NULL;
}

void	swap(t_list *a, t_list *b)
{
	long long int	tmp;

	if (a != NULL && a->next != NULL)
	{
		tmp = a->nbr;
		a->nbr = a->next->nbr;
		a->next->nbr = tmp;
	}
	if (b != NULL && b->next != NULL)
	{
		tmp = b->nbr;
		b->nbr = b->next->nbr;
		b->next->nbr = tmp;
	}
}

void	rotate(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (a != NULL && *a != NULL && (*a)->next != NULL)
	{
		tmp = *a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *a;
		*a = (*a)->next;
		tmp->next->next = NULL;
		tmp = NULL;
	}
	if (b != NULL && *b != NULL && (*b)->next != NULL)
	{
		tmp = *b;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *b;
		*b = (*b)->next;
		tmp->next->next = NULL;
		tmp = NULL;
	}
}

void	reverse(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = NULL;
	if (a != NULL && *a != NULL && (*a)->next != NULL)
	{
		tmp = *a;
		while (tmp->next && tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = *a;
		*a = tmp->next;
		tmp->next = NULL;
		tmp = NULL;
	}
	if (b != NULL && *b != NULL && (*b)->next != NULL)
	{
		tmp = *b;
		while (tmp->next && tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = *b;
		*b = tmp->next;
		tmp->next = NULL;
		tmp = NULL;
	}
}
