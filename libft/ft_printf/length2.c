/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 16:58:51 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:23:43 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	z(int *formatted, va_list arg, t_type *type, int base)
{
	if ((formatted[(int)'d'] || formatted[(int)'i']) == 1)
		type->str = ft_itoa_base(va_arg(arg, int64_t), base);
	else
		type->str = ft_utoa_base(va_arg(arg, size_t), base);
}
