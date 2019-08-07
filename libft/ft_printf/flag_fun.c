/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 19:26:46 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:23:38 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hash(int *formatted, t_type *type)
{
	if (formatted[(int)'#'])
	{
		while (type->bytes + 2 >= MAX_BUFF)
			resize(type);
		if ((formatted[(int)'o'] || formatted[(int)'O']) && *type->str != '0')
			type->bytes += ft_strlen(ft_strncpy(type->buff + type->bytes, "0",
			1));
		if (formatted[(int)'X'])
			type->bytes += ft_strlen(ft_strncpy(type->buff + type->bytes, "0X",
			2));
		else if (formatted[(int)'x'])
			type->bytes += ft_strlen(ft_strncpy(type->buff + type->bytes, "0x",
			2));
	}
}

void	width(int *formatted, t_type *type, int i)
{
	if (formatted[(int)' '] && type->str && type->str[0] != '-')
		*(type->buff + type->bytes + i++) = ' ';
	if (!formatted[(int)'-'] && formatted[(int)'0'] && (!type->precision &&
	!formatted[(int)'.']))
	{
		minus_plus(formatted, type);
		while (i < type->width && type->width)
			*(type->buff + type->bytes + i++) = '0';
		type->width = 0;
	}
	else if (!formatted[(int)'-'] && type->width && ((formatted[(int)'0'] &&
	formatted[(int)'.']) || !formatted[(int)'0']))
	{
		while (i < ft_abs(type->width, type->precision))
			*(type->buff + type->bytes + i++) = ' ';
		type->width = 0;
	}
	if ((ft_strrchr(type->buff, '+') && i > 0) || (type->buff[type->bytes] !=
	' ' && i == 1))
		i -= 1;
	type->bytes += i;
}

void	minus_plus(int *formatted, t_type *type)
{
	if (!formatted[(int)'s'] && !formatted[(int)'S'])
	{
		if (type->str && type->str[0] == '-')
		{
			type->bytes += ft_strlen(ft_strncpy(type->buff + type->bytes, "-",
			1));
			type->str++;
		}
		else if (formatted[43] && (formatted[(int)'d'] || formatted[(int)'i']))
			type->bytes += ft_strlen(ft_strncpy(type->buff + type->bytes, "+",
			1));
		formatted[(int)'+'] = 0;
	}
}
