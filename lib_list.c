/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:12:21 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:46:01 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

t_list	*ft_lstnew(long long int nbr)
{
	t_list	*lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst->nbr = nbr;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd(t_list **head, long long int nbr)
{
	t_list	*lst;

	lst = *head;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = ft_lstnew(nbr);
	}
	else
		*head = ft_lstnew(nbr);
}

void	ft_lstfree(t_list **lst)
{
	t_list	*curr;

	if (*lst == NULL)
		return ;
	while (*lst)
	{
		curr = *lst;
		*lst = (*lst)->next;
		free(curr);
		curr = NULL;
	}
}

int		is_sort(t_list *a, t_list *b)
{
	int	i;

	i = 1;
	while (a && a->next)
	{
		if (a->nbr >= a->next->nbr)
			return (i);
		a = a->next;
		i++;
	}
	i = 1;
	while (b && b->next)
	{
		i++;
		if (b->nbr <= b->next->nbr)
			return (i);
		b = b->next;
	}
	return (0);
}

void	ft_lstsfree(t_list **lst1, t_list **lst2)
{
	t_list *curr;

	if (*lst1 != NULL)
		while (*lst1)
		{
			curr = *lst1;
			*lst1 = (*lst1)->next;
			free(curr);
			curr = NULL;
		}
	if (*lst2 != NULL)
		while (*lst2)
		{
			curr = *lst2;
			*lst2 = (*lst2)->next;
			free(curr);
			curr = NULL;
		}
}
