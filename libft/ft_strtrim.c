/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 23:36:06 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:33:14 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_end(const char *str, size_t len)
{
	while (str[len] == ' ' || str[len] == '\n' || str[len] == '\t')
	{
		if (len == 0)
			break ;
		len--;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (!s[i])
		return ((char *)&s[i]);
	j = ft_strlen(s);
	k = ft_find_end(s, j - 1) - i + 1;
	str = ft_strnew(k);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, &s[i], k);
	str[k] = '\0';
	return (str);
}
