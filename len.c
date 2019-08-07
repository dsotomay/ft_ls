/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:05:26 by dysotoma          #+#    #+#             */
/*   Updated: 2018/09/12 19:05:29 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_reset(t_ls *ls)
{
	ls->len_dir_name = 0;
	ls->len_nlnk = 0;
	ls->len_size = 0;
	ls->blk_size = 0;
	ls->len_uid = 0;
	ls->len_gid = 0;
	ls->dir_num = 0;
	ls->tmp = 0;
}

static int	maj_min_dev(t_ls *ls, int *i)
{
	int tmp;
	int width;
	int n;

	width = 0;
	tmp = 0;
	n = major(ls->list[*i]->buf.st_rdev);
	while (n)
	{
		n /= 10;
		width++;
	}
	(S_ISBLK(ls->list[*i]->buf.st_mode) || S_ISCHR(ls->list[*i]->buf.st_mode)) ?
	tmp = ft_sprintf(ls->list[*i]->dev_num, "% *d, %*d", width,
	major(ls->list[*i]->buf.st_rdev), 3, minor(ls->list[*i]->buf.st_rdev)) : 0;
	ls->list[*i]->d_num = (tmp > 0) ? 1 : 0;
	return (tmp);
}

int			get_len_full(t_ls *ls, struct dirent *dp, int *i)
{
	ft_strcat(ls->list[*i]->curr_path, dp->d_name);
	if (lstat(ls->list[*i]->curr_path, &ls->list[*i]->buf))
		return (1);
	ft_strcat(ls->list[*i]->sub_dir_list, dp->d_name);
	ls->blk_size += ls->list[*i]->buf.st_blocks;
	ls->len_dir_name = (ls->len_dir_name >= dp->d_namlen) ?
	ls->len_dir_name : dp->d_namlen;
	ls->len_gid = (ls->len_gid >=
	LEN(getgrgid(ls->list[*i]->buf.st_gid)->gr_name)) ?
	ls->len_gid : LEN(getgrgid(ls->list[*i]->buf.st_gid)->gr_name);
	if ((getpwuid(ls->list[*i]->buf.st_uid)->pw_name))
		ls->len_uid = (ls->len_uid >=
		LEN(getpwuid(ls->list[*i]->buf.st_uid)->pw_name)) ?
		ls->len_uid : LEN(getpwuid(ls->list[*i]->buf.st_uid)->pw_name);
	ls->len_nlnk = (ls->len_nlnk >=
	LEN(ft_itoa(ls->list[*i]->buf.st_nlink))) ?
	ls->len_nlnk : LEN(ft_itoa(ls->list[*i]->buf.st_nlink));
	ls->tmp = maj_min_dev(ls, i);
	if (ls->len_size < LEN(ft_itoa(ls->list[*i]->buf.st_size)))
		ls->len_size = LEN(ft_itoa(ls->list[*i]->buf.st_size));
	if (ls->len_size < ls->tmp)
		ls->len_size = ls->tmp;
	(*i)++;
	return (0);
}

int			get_len(t_ls *ls, struct dirent *dp, int *i)
{
	if ((dp->d_name[0] != '.') || ft_strcmp(ls->curr_dir, ".") == 0)
	{
		if (get_len_full(ls, dp, i))
			return (1);
	}
	return (0);
}

void		get_len_link(t_ls *ls, struct dirent *dp, int i)
{
	lstat(ls->curr_dir, &ls->list[i]->buf);
	ft_strcat(ls->list[i]->sub_dir_list, dp->d_name);
	ls->len_dir_name = dp->d_namlen;
	ls->len_gid = LEN(getgrgid(ls->list[i]->buf.st_gid)->gr_name);
	ls->len_uid = LEN(getpwuid(ls->list[i]->buf.st_uid)->pw_name);
	ls->len_nlnk = LEN(ft_itoa(ls->list[i]->buf.st_nlink));
	ls->len_size = LEN(ft_itoa(ls->list[i]->buf.st_size));
}
