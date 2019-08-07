/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 23:14:33 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:33:08 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && i < n)
	{
		if (s1[i])
			i++;
		else
			return (1);
	}
	if (!s1[i] || i == n)
		return (1);
	return (0);
}
