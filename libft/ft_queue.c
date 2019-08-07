/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 21:23:11 by dysotoma          #+#    #+#             */
/*   Updated: 2018/08/28 21:23:14 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue	*ft_queue(void)
{
	t_queue	*q;

	if (!(q = (t_queue*)ft_memalloc(sizeof(t_queue))))
		return (NULL);
	return (q);
}

void	enqueue(t_queue *q, void *content)
{
	t_list	*tmp;

	ft_lstadd(&tmp, ft_lstnew(content, ft_strlen((char*)content) + 1));
	if (q->end == NULL)
	{
		q->start = tmp;
		q->end = tmp;
		return ;
	}
	q->end->next = tmp;
	q->end = tmp;
}

char	*dequeue(t_queue *q)
{
	t_list	*tmp;
	char	*ret;

	if (q->start == NULL)
		return (NULL);
	tmp = q->start;
	q->start = q->start->next;
	ret = ft_strdup(tmp->content);
	ft_memdel(&tmp->content);
	ft_memdel((void**)&tmp);
	return (ret);
}
