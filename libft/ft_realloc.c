/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 18:54:38 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/15 18:54:45 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	if (ptr)
		free(ptr);
	if (!(ptr = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	return (ptr);
}
