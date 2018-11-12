/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <vlevko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:13:57 by vlevko            #+#    #+#             */
/*   Updated: 2018/04/08 17:47:23 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ps.h"

static int	check_result(t_list **a, t_list **b)
{
	if (is_sort(*a, NULL) != 0)
	{
		ft_lstfree(a);
		ft_lstfree(b);
		return (say("KO"));
	}
	if (*b != NULL)
	{
		ft_lstfree(a);
		ft_lstfree(b);
		return (say("KO"));
	}
	return (0);
}

static int	check_buff(t_list **a, t_list **b, ssize_t i)
{
	char	*buff;

	while ((i = get_next_line(0, &buff)) != 0)
	{
		if (i == -1)
		{
			ft_lstsfree(a, b);
			if (buff)
				ft_strdel(&buff);
			return (err());
		}
		if ((i = buff_check_exec(a, b, buff)) == -1)
		{
			ft_lstsfree(a, b);
			if (buff)
				ft_strdel(&buff);
			return (err());
		}
		if (buff)
			ft_strdel(&buff);
	}
	return (0);
}

static int	check_args(char **av, t_list **a, int i, int neg)
{
	while ((*av)[i])
	{
		if ((*av)[i] == '-' && neg != 1)
		{
			i++;
			neg = 1;
		}
		else if ((*av)[i] == '-')
		{
			ft_lstfree(a);
			return (err());
		}
		if (ft_isdigit((*av)[i]) == 0)
		{
			ft_lstfree(a);
			return (err());
		}
		if (neg == 0)
			neg = 1;
		i++;
	}
	return (0);
}

static int	check_list(t_list **a)
{
	if (is_same(*a) || is_lld(*a))
	{
		ft_lstfree(a);
		return (1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac != 1)
	{
		av++;
		while (*av)
		{
			if (check_args(av, &a, 0, 0) != 0)
				return (1);
			ft_lstadd(&a, ft_atoi(*av));
			av++;
		}
		if (check_list(&a) != 0)
			return (1);
		if (check_buff(&a, &b, -1) != 0)
			return (1);
		if (check_result(&a, &b) != 0)
			return (1);
		say("OK");
		ft_lstsfree(&a, &b);
	}
	return (0);
}
