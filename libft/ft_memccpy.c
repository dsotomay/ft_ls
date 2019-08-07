/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:51:52 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:32:17 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*sorc;

	dest = dst;
	sorc = src;
	while (n)
	{
		if ((*dest++ = *sorc++) == (unsigned char)c)
			return (dest);
		n--;
	}
	return (0);
}
