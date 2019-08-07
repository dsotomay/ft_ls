/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 17:43:21 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:32:15 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	if (!(newlst = ft_memalloc(sizeof(t_list))))
		return (NULL);
	newlst->content = 0;
	newlst->content_size = 0;
	if (content)
	{
		if (!(newlst->content = ft_memalloc(content_size)))
		{
			ft_memdel(&newlst->content);
			return (0);
		}
		else
		{
			ft_memcpy(newlst->content, content, content_size);
			newlst->content_size = content_size;
		}
	}
	return (newlst);
}
