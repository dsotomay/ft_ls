/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:26:59 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:32:22 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t len)
{
	size_t		n;
	char		*dst;
	const char	*src;

	dst = (char *)d;
	src = (const char *)s;
	n = 0;
	if (src < dst)
	{
		while (len)
		{
			dst[len - 1] = src[len - 1];
			len--;
		}
		return (dst);
	}
	while (n < len)
	{
		dst[n] = src[n];
		n++;
	}
	return (dst);
}
