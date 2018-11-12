/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:24:02 by vlevko            #+#    #+#             */
/*   Updated: 2017/11/22 15:54:18 by vlevko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size-- > 0)
		str[size] = '\0';
	return (str);
}
