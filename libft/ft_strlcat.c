/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:21:05 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:32:56 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dest[i] && i < dstsize)
		i++;
	while (j + i + 1 < dstsize && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i != dstsize)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
