/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:30:54 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:33:09 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	if (*str == 0 && *to_find == 0)
		return ((char *)str);
	if (*to_find == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) < n)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
