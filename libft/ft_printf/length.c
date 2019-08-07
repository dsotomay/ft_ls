/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:52:17 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:23:42 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hh(int *formatted, va_list arg, t_type *type, int base)
{
	char	c;

	(void)base;
	if ((formatted[(int)'d'] || formatted[(int)'i']) == 1)
	{
		c = (char)va_arg(arg, int);
		if (type->bytes + 1 >= MAX_BUFF)
			resize(type);
		if (c == 0)
			*(type->buff + type->bytes) = '0';
		else
			*(type->buff + type->bytes) = c;
		type->bytes += 1;
		return ;
	}
	else
		type->str = ft_utoa_base(va_arg(arg, uint64_t), base);
}

void	h(int *formatted, va_list arg, t_type *type, int base)
{
	short	c;

	if (formatted[(int)'h'] == 2)
		hh(formatted, arg, type, base);
	else
	{
		(void)base;
		if ((formatted[(int)'d'] || formatted[(int)'i']) == 1)
		{
			c = (short)va_arg(arg, int);
			if (type->bytes + 1 >= MAX_BUFF)
				resize(type);
			if (c == 0)
				*(type->buff + type->bytes) = '0';
			else
				*(type->buff + type->bytes) = c;
			type->bytes += 1;
			return ;
		}
		else
			type->str = ft_utoa_base(va_arg(arg, uint64_t), base);
	}
}

void	ll(int *formatted, va_list arg, t_type *type, int base)
{
	if (formatted[(int)'d'] || formatted[(int)'i'])
		type->str = ft_itoa_base(va_arg(arg, long long), base);
	else
		type->str = ft_utoa_base(va_arg(arg, unsigned long long), base);
}

void	l(int *formatted, va_list arg, t_type *type, int base)
{
	if (formatted[(int)'h'] == 2)
		ll(formatted, arg, type, base);
	else
	{
		if ((formatted[(int)'d'] || formatted[(int)'i']))
			type->str = ft_itoa_base(va_arg(arg, long), base);
		else
			type->str = ft_utoa_base(va_arg(arg, unsigned long), base);
	}
}

void	j(int *formatted, va_list arg, t_type *type, int base)
{
	if ((formatted[(int)'d'] || formatted[(int)'i']) == 1)
		type->str = ft_itoa_base(va_arg(arg, intmax_t), base);
	else
		type->str = ft_utoa_base(va_arg(arg, uintmax_t), base);
}
