/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:27:37 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:32:14 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *startnewlst;

	if (!lst->next)
		return (NULL);
	newlst = f(lst);
	startnewlst = newlst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(newlst->next = f(lst)))
		{
			free(newlst->next);
			return (NULL);
		}
		newlst = newlst->next;
	}
	return (startnewlst);
}
