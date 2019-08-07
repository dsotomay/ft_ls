/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 18:51:33 by dysotoma          #+#    #+#             */
/*   Updated: 2018/08/06 18:51:37 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_l(char *curr_dir, t_ls *ls)
{
	if (S_ISLNK(ls->buf.st_mode) && ls->dir_num == 1)
		list_content(curr_dir, ls);
	else
	{
		ft_printf("total %d\n", ls->blk_size);
		list_content(curr_dir, ls);
	}
}

int		number_of_dir(char *str, t_ls *ls)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				tp;

	if (!(dirp = opendir(str)))
	{
		ft_bzero(ls->curr_dir + (LEN(str)), 1024 - (LEN(str)));
		ft_strncpy(str + LEN(str) - 1, "\0", 1);
		tp = ft_sprintf(ls->curr_dir + LEN(ls->curr_dir), "ft_ls: %.*s: %*s\n",
		LEN(SRC(str, '/')) ? LEN(SRC(str, '/')) : LEN(str), !SRC(str, '/') ?
		str : SRC(str, '/') + 1, LEN(strerror(errno)), strerror(errno));
		write(2, ls->curr_dir + (LEN(ls->curr_dir) - tp), tp);
		return (-1);
	}
	while ((dp = readdir(dirp)) != NULL)
	{
		if (S_ISLNK(ls->buf.st_mode) && ls->l)
		{
			ls->dir_num = 1;
			break ;
		}
		(ls->a || dp->d_name[0] != '.') ? ls->dir_num++ : 0;
	}
	closedir(dirp);
	return (0);
}

void	free_list(t_ls *ls)
{
	int i;

	i = -1;
	if (!ls->list)
		return ;
	while (ls->list[++i])
		ft_memdel((void**)&ls->list[i]);
	free(ls->list);
}

int		make_list(char *cd, t_ls *ls)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				i;

	i = 0;
	if ((dirp = opendir(cd)) == NULL)
		return (0);
	while ((dp = readdir(dirp)) != NULL && i < ls->dir_num)
	{
		if (!ls->a && (dp->d_name[0] == '.' || CMP(ls->curr_dir, ".") == 0
											|| CMP(dp->d_name, "..") == 0))
			continue ;
		if (!(ls->list[i] = (t_subdir *)ft_memalloc(sizeof(t_subdir))))
			return (closedir(dirp));
		ls->list[i] ? ft_strcat(ls->list[i]->curr_path, cd) : 0;
		if (S_ISLNK(ls->buf.st_mode) && ls->dir_num == 1 && ls->l)
		{
			get_len_link(ls, dp, i);
			break ;
		}
		if (ls->a ? get_len_full(ls, dp, &i) : get_len(ls, dp, &i))
			return (closedir(dirp));
	}
	closedir(dirp);
	return (1);
}

void	list_content(char *str, t_ls *ls)
{
	int				i;
	char			path[1024];
	int				len;

	i = -1;
	len = ft_strlen(str);
	ft_strcpy(path, str);
	ft_qsort_struct(0, ls->dir_num - 1, ls);
	if (S_ISLNK(ls->buf.st_mode) && ls->dir_num == 1 && ls->l)
		print_long(path, ls, 0, str);
	else
		while (++i < ls->dir_num)
		{
			ft_bzero(path + len, ft_strlen(path) - len);
			ft_strcat(path, ls->list[i]->sub_dir_list);
			if (ls->up_r && S_ISDIR(ls->list[i]->buf.st_mode))
				enqueue(ls->queue, ls->list[i]->curr_path);
			ls->l ? print_long(path, ls, i, str) : print(ls, i);
			!ls->queue ? free(ls->queue) : 0;
		}
}
