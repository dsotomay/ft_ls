/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_char_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:15:06 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:42:25 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s(int *formatted, va_list arg, t_type *type, int base)
{
	if (formatted[(int)'l'] == 0)
	{
		(void)base;
		if (!(type->str = va_arg(arg, char*)))
		{
			type->bytes += ft_strlen(ft_strncpy(type->buff + type->bytes,
			"(null)", 6));
			return ;
		}
		while (type->str && type->bytes + ft_strlen(type->str) >= MAX_BUFF)
			resize(type);
		if (formatted[(int)'s'] == 1)
		{
			put_min_max_width(formatted, type);
			type->bytes += ft_strlen(ft_strncpy(type->buff + type->bytes,
			type->str, !type->precision ? (int64_t)ft_strlen(type->str) :
			type->precision));
		}
	}
	else if (formatted[(int)'l'] == 1)
		up_s(formatted, arg, type, base);
}

void	up_s(int *formatted, va_list arg, t_type *type, int base)
{
	wchar_t *str;

	(void)base;
	if (!(str = va_arg(arg, wchar_t*)))
	{
		type->bytes += ft_strlen(ft_strncpy(type->buff + type->bytes, "(null)",
		6));
		return ;
	}
	while (str && type->bytes + ft_wstrlen(str) >= MAX_BUFF)
		resize(type);
	if (formatted[(int)'S'] || (formatted[(int)'s'] && formatted[(int)'l']))
	{
		put_min_max_width(formatted, type);
		type->bytes += ft_strlen(ft_ws_to_strncpy(type->buff + type->bytes, str,
		!type->precision ? (int64_t)ft_wstrlen(str) : type->precision));
	}
}

void	p(int *formatted, va_list arg, t_type *type, int base)
{
	char	*ptr;

	(void)base;
	ptr = ft_itoa_base((int64_t)va_arg(arg, void*), 16);
	while (type->bytes + ft_strlen(ptr) >= MAX_BUFF)
		resize(type);
	if (formatted[(int)'p'] == 1)
	{
		type->bytes += ft_strlen(ft_strncpy(type->buff + type->bytes, "0x", 2));
		if (!*ptr)
			type->bytes += ft_strlen(ft_strncpy(type->buff + type->bytes, "0",
			1));
		else
			type->bytes += ft_strlen(ft_strncpy(type->buff + type->bytes, ptr,
			ft_strlen(ptr)));
	}
}

void	c(int *formatted, va_list arg, t_type *type, int base)
{
	char c;

	if (formatted[(int)'l'] == 0)
	{
		(void)base;
		c = (char)va_arg(arg, int);
		if (type->bytes + 1 >= MAX_BUFF)
			resize(type);
		if (formatted[(int)'c'])
		{
			*(type->buff + type->bytes) = c;
			type->bytes += 1;
		}
	}
	else if (formatted[(int)'l'] == 1)
		up_c(formatted, arg, type, base);
}

void	up_c(int *formatted, va_list arg, t_type *type, int base)
{
	wchar_t c;

	(void)base;
	c = (wchar_t)va_arg(arg, int);
	if (type->bytes + 1 >= MAX_BUFF)
		resize(type);
	if (formatted[(int)'C'])
	{
		*(type->buff + type->bytes) = c;
		type->bytes += 1;
	}
}
