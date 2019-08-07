/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:17:04 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:23:33 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_specifier(int *formatted, va_list arg, t_type *type)
{
	int			i;
	int			base;
	t_dispatch	dispatch;

	i = 65;
	base = 0;
	while ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
	{
		while (length(i))
			i++;
		if (i == 90)
			i = 97;
		if (formatted[i])
		{
			dispatch.func = spec(i);
			(dispatch.func)(formatted, arg, type, base);
			break ;
		}
		else
			i++;
	}
}

void	set_length(int *formatted, va_list arg, t_type *type, int base)
{
	int			i;
	t_dispatch	dispatch;

	i = 104;
	while (i >= 104 && i <= 122)
	{
		while (specifier(i))
			i++;
		if (formatted[i])
		{
			dispatch.func = spec(i);
			(dispatch.func)(formatted, arg, type, base);
			break ;
		}
		else
			i++;
	}
}

void	handle(char *format, va_list arg, int *i, t_type *type)
{
	static	int	formatted[128];
	int			end;

	end = 0;
	while (format[*i] && !end)
	{
		if (flags(format[*i]) || length(format[*i]) || ft_isdigit(format[*i])
		|| (format[*i] == '.') || specifier(format[*i]))
		{
			if ((ft_isdigit(format[*i]) && format[*i] != '0')
			|| format[*i] == '*')
				set_width(format, arg, i, type);
			if (specifier(format[*i]))
				end = 1;
			formatted[(int)format[*i]] += 1;
			*i += 1;
		}
		else
			return ;
	}
	set_specifier(formatted, arg, type);
	while (type->width-- && formatted[(int)'-'])
		type->bytes += ft_strlen(ft_strncpy(type->buff + type->bytes, " ", 1));
	reset(formatted);
	type->precision = 0;
}

void	parse(char *format, va_list arg, int *i, t_type *type)
{
	while (format[*i] != '%' && format[*i])
	{
		resize(type);
		type->bytes += ft_strlen(ft_strncpy(type->buff + type->bytes, format +
		*i, 1));
		(*i)++;
	}
	if (format[*i])
	{
		if (type->bytes + 2 == MAX_BUFF)
			resize(type);
		if (format[++*i] == '%')
		{
			ft_strncpy(type->buff + type->bytes, "%", 1);
			type->bytes++;
			(*i)++;
		}
		else
			handle(format, arg, i, type);
	}
}
