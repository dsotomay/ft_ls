/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 22:56:59 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:23:41 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define INIT int i = 0; int tmp = 0

void	resize(t_type *type)
{
	if (!type->str)
		return ;
	if (type->bytes + 2 == MAX_BUFF || type->bytes + ft_strlen(type->str)
			>= MAX_BUFF)
	{
		type->count++;
		type->buff = (char*)ft_realloc(type->buff, MAX_BUFF + 2);
	}
}

void	set_width(char *format, va_list arg, int *i, t_type *type)
{
	int set;

	set = 0;
	if (format[*i] != '*')
	{
		if (format[*i - 1] != '.')
			type->width = ft_atoi(format + *i);
		else
			type->precision = ft_atoi(format + *i);
		while (ft_isdigit(format[*i]))
			(*i)++;
		return ;
	}
	set = va_arg(arg, int);
	if (format[*i - 1] != '.')
		type->width = set;
	else
		type->precision = set;
	*i += 1;
}

int		check_length(int *formatted)
{
	return (formatted[104] || formatted[106] || formatted[108] ||
			formatted[122]);
}

void	put_min_max_width(int *formatted, t_type *type)
{
	INIT;
	if (type->str)
		tmp = ft_strlen(type->str);
	if (type->precision == tmp)
		type->precision = 0;
	if (type->width <= tmp || type->width < type->precision)
		type->width = 0;
	else if (type->width > tmp + type->precision && (!formatted[(int)'s'] ||
				!formatted[(int)'S']))
		type->width -= tmp + type->precision;
	else if (type->width > tmp && (formatted[(int)'s'] || formatted[(int)'S'])
			&& type->precision)
		type->width -= type->precision;
	if (tmp > 0 && type->str[0] == '-' && type->width)
		i = 1;
	width(formatted, type, i);
	minus_plus(formatted, type);
	i = 0;
	if (type->precision > tmp && !formatted[(int)'s'])
		while (i + tmp < type->precision)
			*(type->buff + type->bytes + i++) = '0';
	if (!formatted[(int)'s'] && !formatted[(int)'S'])
		type->precision = 0;
	type->bytes += i;
}

void	reset(int *formatted)
{
	formatted[(int)'s'] = 0;
	formatted[(int)'S'] = 0;
	formatted[(int)'p'] = 0;
	formatted[(int)'d'] = 0;
	formatted[(int)'D'] = 0;
	formatted[(int)'i'] = 0;
	formatted[(int)'o'] = 0;
	formatted[(int)'O'] = 0;
	formatted[(int)'u'] = 0;
	formatted[(int)'U'] = 0;
	formatted[(int)'x'] = 0;
	formatted[(int)'X'] = 0;
	formatted[(int)'c'] = 0;
	formatted[(int)'C'] = 0;
	formatted[(int)'h'] = 0;
	formatted[(int)'l'] = 0;
	formatted[(int)'j'] = 0;
	formatted[(int)'z'] = 0;
	formatted[(int)'#'] = 0;
	formatted[(int)'0'] = 0;
	formatted[(int)'-'] = 0;
	formatted[(int)'+'] = 0;
	formatted[(int)' '] = 0;
	formatted[(int)'.'] = 0;
	formatted[(int)'*'] = 0;
}
