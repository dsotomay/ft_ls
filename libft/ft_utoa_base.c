/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:32:32 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:33:17 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(uint64_t num, int base)
{
	static	char	num_rep[16] = "0123456789abcdef";
	static	char	buff[50];
	char			*ptr;

	ptr = &buff[49];
	*ptr = '\0';
	*(ptr - 1) = '0';
	while (num)
	{
		*--ptr = num_rep[num % base];
		num /= base;
	}
	return (!*ptr ? ptr - 1 : ptr);
}
