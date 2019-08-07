/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:39:53 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:33:11 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wc(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c && *str)
			if (*(str + 1) == c || !*(str + 1))
				count++;
		str++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	index;
	size_t	count;
	char	**str;

	i = 0;
	index = 0;
	if (!(str = (char **)ft_memalloc(sizeof(char *) * (ft_wc(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		count = 0;
		while (s[i + count] != c && s[i + count])
			count++;
		if (!(str[index] = ft_strsub(s, i, count)))
			return (NULL);
		i = i + count;
		index++;
	}
	str[index] = 0;
	return (str);
}
