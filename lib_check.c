/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:15:11 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/06 17:45:45 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

int		check_exec_swap(t_list **a, t_list **b, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
	{
		swap(*a, NULL);
		return (0);
	}
	else if (ft_strcmp(str, "sb") == 0)
	{
		swap(NULL, *b);
		return (0);
	}
	else if (ft_strcmp(str, "ss") == 0)
	{
		swap(*a, *b);
		return (0);
	}
	return (1);
}

int		check_exec_rotate(t_list **a, t_list **b, char *str)
{
	if (ft_strcmp(str, "ra") == 0)
	{
		rotate(a, NULL);
		return (0);
	}
	else if (ft_strcmp(str, "rb") == 0)
	{
		rotate(NULL, b);
		return (0);
	}
	else if (ft_strcmp(str, "rr") == 0)
	{
		rotate(a, b);
		return (0);
	}
	return (1);
}

int		check_exec_reverse(t_list **a, t_list **b, char *str)
{
	if (ft_strcmp(str, "rra") == 0)
	{
		reverse(a, NULL);
		return (1);
	}
	else if (ft_strcmp(str, "rrb") == 0)
	{
		reverse(NULL, b);
		return (1);
	}
	else if (ft_strcmp(str, "rrr") == 0)
	{
		reverse(a, b);
		return (1);
	}
	return (-1);
}

int		buff_check_exec(t_list **a, t_list **b, char *str)
{
	if (check_exec_swap(a, b, str) == 0)
		return (0);
	else if (ft_strcmp(str, "pa") == 0)
	{
		push(a, b);
		return (0);
	}
	else if (ft_strcmp(str, "pb") == 0)
	{
		push(b, a);
		return (0);
	}
	else if (check_exec_rotate(a, b, str) == 0)
		return (0);
	else if (check_exec_reverse(a, b, str) == 1)
		return (1);
	return (-1);
}

void	exec(t_list **a, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		swap(*a, NULL);
}
