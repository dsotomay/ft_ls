/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:54:51 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:23:40 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define INIT int i = 0; t_type type; va_list arg

int	ft_printf(char *format, ...)
{
	INIT;
	va_start(arg, format);
	type.count = 1;
	type.bytes = 0;
	type.width = 0;
	type.str = NULL;
	type.precision = 0;
	type.buff = ft_strnew(1023);
	while (format[i] && type.bytes != (size_t)-1)
	{
		if (format[i] == '%' && !format[i + 1])
			break ;
		else
			parse(format, arg, &i, &type);
	}
	va_end(arg);
	if (type.bytes != (size_t)-1)
		write(1, type.buff, type.bytes);
	if (*type.buff)
		free(type.buff);
	return (type.bytes != (size_t)-1 ? (int64_t)type.bytes : -1);
}

int	ft_sprintf(char *str, char *format, ...)
{
	INIT;
	va_start(arg, format);
	type.count = 1;
	type.bytes = 0;
	type.width = 0;
	type.str = NULL;
	type.precision = 0;
	type.buff = ft_strnew(1023);
	while (format[i] && type.bytes != (size_t)-1)
	{
		if (format[i] == '%' && !format[i + 1])
			break ;
		else
			parse(format, arg, &i, &type);
	}
	va_end(arg);
	if (type.bytes != (size_t)-1)
		ft_strcpy(str, type.buff);
	if (*type.buff)
		free(type.buff);
	return (type.bytes != (size_t)-1 ? (int64_t)type.bytes : -1);
}
