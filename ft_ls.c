/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:58:59 by dysotoma          #+#    #+#             */
/*   Updated: 2018/09/12 15:59:03 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define INITII ls.len_gid = 0; ls.len_nlnk = 0; ls.dir_num = 0; ls.blk_size = 0
#define INITI ls.len_dir_name = 0; ls.len_size = 0; ls.len_uid = 0; INITII

void			ls_parse(char *cd, t_ls *ls)
{
	int tmp;

	tmp = lstat(cd, &ls->buf);
	(!S_ISLNK(ls->buf.st_mode) || (!ls->l && S_ISLNK(ls->buf.st_mode)) ||
	tmp == -1) ? ft_strcat(cd, "/\0") : 0;
	ls->error = ft_strdup(cd);
	if (number_of_dir(cd, ls) == -1)
	{
		ft_bzero(cd + LEN(ls->error), 1024 - LEN(ls->error));
		free(ls->error);
		return ;
	}
	free(ls->error);
	lstat(cd, &ls->buf);
	if (!(ls->list = (t_subdir**)ft_memalloc(sizeof(t_subdir*) *
													(ls->dir_num + 1))))
		return ;
	if (!make_list(cd, ls))
	{
		free_list(ls);
		return ;
	}
	ls->l ? ls_l(cd, ls) : list_content(cd, ls);
	free_list(ls);
}

static t_queue	*check_dot(char *new, char *path, t_ls *ls)
{
	char		*tp;
	t_queue		*queue;

	tp = NULL;
	queue = ft_queue();
	ft_bzero(new, 1024);
	if (CMP(SRC(path, '/') + 1, "..") != 0 && CMP(SRC(path, '/') + 1, ".") != 0)
		ft_printf("\n%s:\n", path);
	ft_strcat(new, tp = dequeue(ls->queue));
	if (CMP(SRC(tp, '/') + 1, "..") == 0 || CMP(SRC(tp, '/') + 1, ".") == 0)
	{
		ft_memdel((void**)&tp);
		ft_memdel((void**)&queue);
		return (NULL);
	}
	ft_memdel((void**)&tp);
	return (queue);
}

static void		recurse(t_ls ls, char *path)
{
	char		new[1024];

	ls_reset(&ls);
	if (!(ls.queue = check_dot(new, path, &ls)))
	{
		ft_memdel((void**)&ls.queue);
		return ;
	}
	ls_parse(new, &ls);
	while (ls.queue->start)
	{
		if (ls.queue->start && ls.queue->start == ls.queue->end)
		{
			recurse(ls, ls.queue->start->content);
			if (ls.queue)
				ft_memdel((void**)&ls.queue);
			break ;
		}
		recurse(ls, ls.queue->start->content);
	}
	ft_memdel((void**)&ls.queue);
}

static void		ft_ls(int *i, char *str, t_ls *ls, int multi)
{
	char	path[1024];

	ft_bzero(path, 1024);
	ls->queue = ft_queue();
	ls->curr_dir = ft_strcpy(path, str);
	ls_parse(path, ls);
	while (ls->up_r && ls->queue && ls->queue->start)
	{
		ft_bzero(path + LEN(str) + 1, 1024 - (LEN(str) + 1));
		if (ls->queue->start && ls->queue->start == ls->queue->end)
		{
			recurse(*ls, ls->queue->start->content);
			ft_memdel((void**)&ls->queue);
			break ;
		}
		recurse(*ls, ls->queue->start->content);
	}
	multi ? ft_printf("\n") : 0;
	ft_bzero(path, 1024);
	(*i)++;
}

int				main(int ac, char **av)
{
	t_ls		ls;
	int			i;
	int			multi;
	static char	path[1024];

	ft_bzero(&ls, sizeof(t_ls));
	i = 1;
	while (av[i] && av[i][0] == '-')
		flag(av[i++], &ls);
	av[i] == NULL && (av[i - 1][0] == '-' || i == 1) ? CPY(path, ".") : av[i--];
	!path[0] && (i == 0 || av[i][0] == '-') ? i++ : 0;
	ft_qsort(av + i, 0, ac - (i + 1), &ls);
	multi = ac - (i + 1);
	while (av[i] || path[0])
	{
		if (path[0])
		{
			ft_ls(&i, path, &ls, multi);
			break ;
		}
		multi ? ft_printf("%s:\n", av[i]) : 0;
		ls_reset(&ls);
		ft_ls(&i, av[i], &ls, multi);
	}
	ft_memdel((void**)&ls.queue);
}
