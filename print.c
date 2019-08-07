/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:04:48 by dysotoma          #+#    #+#             */
/*   Updated: 2018/09/12 19:04:50 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	print_long(char *path, t_ls *ls, int i, char *curr_dir)
{
	char *mod_time;
	char tmp[65];

	ft_bzero(tmp, 65);
	ft_strcpy(tmp, ft_itoa(ls->list[i]->buf.st_size));
	mod_time = ctime(&ls->list[i]->buf.st_mtime);
	ft_printf("%-11s %*i %-*s %-*s %*s %.3s %2.2s %5.5s %s\n",
	set_perm(ls, i), ls->len_nlnk, ls->list[i]->buf.st_nlink, ls->len_uid + 1,
	getpwuid(ls->list[i]->buf.st_uid)->pw_name, ls->len_gid + 1,
	getgrgid(ls->list[i]->buf.st_gid)->gr_name, ls->len_size,
	ls->list[i]->d_num ? ls->list[i]->dev_num : tmp, mod_time + 4, mod_time + 8,
	(time(NULL) - ls->list[i]->buf.st_mtimespec.tv_sec > 15778476) ?
	mod_time + 19 : mod_time + 11, S_ISLNK(ls->list[i]->buf.st_mode) ?
	get_link(path, ls, i, curr_dir) : ls->list[i]->sub_dir_list);
}

void	print(t_ls *ls, int i)
{
	ft_printf("%s\n", ls->list[i]->sub_dir_list);
}
