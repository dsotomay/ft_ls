/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:30:56 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:32:41 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
