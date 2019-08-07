/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:32:32 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:32:08 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int64_t n, int base)
{
	static	char	num_rep[16] = "0123456789abcdef";
	static	char	buff[65];
	char			*ptr;
	uint64_t		num;
	int				sign;

	sign = 1;
	ptr = &buff[64];
	*ptr = '\0';
	*(ptr - 1) = '0';
	if (n < 0)
	{
		sign = -1;
		num = n * -1;
	}
	else
		num = n;
	while (num)
	{
		*--ptr = num_rep[num % base];
		num /= base;
	}
	if (sign == -1 && base == 10)
		*--ptr = '-';
	return (!*ptr ? ptr - 1 : ptr);
}
