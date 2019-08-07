/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 19:14:28 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:23:37 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_func	leng(t_func funct[], int num)
{
	funct[(int)'h'] = h;
	funct[(int)'l'] = l;
	funct[(int)'j'] = j;
	funct[(int)'z'] = z;
	return (funct[num]);
}

t_func			spec(int num)
{
	static t_func	funct[128];

	if (specifier((char)num))
	{
		funct[(int)'s'] = s;
		funct[(int)'S'] = up_s;
		funct[(int)'p'] = p;
		funct[(int)'d'] = d;
		funct[(int)'D'] = up_d;
		funct[(int)'i'] = i;
		funct[(int)'o'] = o;
		funct[(int)'O'] = up_o;
		funct[(int)'u'] = u;
		funct[(int)'U'] = up_u;
		funct[(int)'x'] = x;
		funct[(int)'X'] = up_x;
		funct[(int)'c'] = c;
		funct[(int)'C'] = up_c;
		return (funct[num]);
	}
	if (length((char)num))
		return (leng(funct, num));
	return (0);
}
