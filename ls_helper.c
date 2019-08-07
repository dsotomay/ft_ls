/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:16:53 by dysotoma          #+#    #+#             */
/*   Updated: 2018/09/12 19:16:58 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define INIT static char str[12]

void	flag(char *str, t_ls *ls)
{
	static char	error[1024];
	char		*t;
	int			size;

	while (*++str)
	{
		if (!ft_strchr("altrR1", *str))
		{
			ft_bzero(error, 1024);
			t = "ft_ls: illegal option -- %c\nusage: ft_ls [-latrR] [file ...]";
			size = ft_sprintf(error, t, *str);
			write(2, error, size);
			exit(1);
		}
		(*str == 'a' || ls->a) ? ls->a = 1 : 0;
		(*str == 'l' || ls->l) ? ls->l = 1 : 0;
		(*str == '1' || ls->one) ? ls->one = 1 : 0;
		(*str == 'r' || ls->r) ? ls->r = 1 : 0;
		(*str == 'R' || ls->up_r) ? ls->up_r = 1 : 0;
		(*str == 't' || ls->t) ? ls->t = 1 : 0;
	}
}

int		list_cmp(char *s1, char *s2, t_ls *ls, int *i)
{
	long	a;
	long	a1;
	long	b;
	long	b1;
	int		ret;

	ret = 0;
	a = ls->list[i[3] ? i[1] : i[0]]->buf.st_mtime;
	a1 = ls->list[i[3] ? i[1] : i[0]]->buf.st_mtimespec.tv_nsec;
	b = ls->list[i[2]]->buf.st_mtime;
	b1 = ls->list[i[2]]->buf.st_mtimespec.tv_nsec;
	if (ls->t)
		ret = ls->r ? (b - a) * -1 : (b - a);
	if (ls->t && ret == 0)
		ret = ls->r ? (b1 - a1) * -1 : (b1 - a1);
	if (!ls->t || ret == 0)
		ret = ls->r ? ft_strcmp(s2, s1) : ft_strcmp(s1, s2);
	return (ret);
}

int		cmp(char *s1, char *s2, t_ls *ls)
{
	long	a;
	long	a1;
	long	b;
	long	b1;
	int		ret;

	ret = 0;
	lstat(s1, &ls->buf);
	a = ls->buf.st_mtime;
	a1 = ls->buf.st_mtimespec.tv_nsec;
	lstat(s2, &ls->buf);
	b = ls->buf.st_mtime;
	b1 = ls->buf.st_mtimespec.tv_nsec;
	if (ls->t)
		ret = ls->r ? (b - a) * -1 : (b - a);
	if (ls->t && ret == 0)
		ret = ls->r ? (b1 - a1) * -1 : (b1 - a1);
	if (!ls->t || ret == 0)
		ret = ls->r ? ft_strcmp(s2, s1) : ft_strcmp(s1, s2);
	return (ret);
}

char	*get_link(char *str, t_ls *ls, int i, char *curr_dir)
{
	static char buff[1024];
	ssize_t		len;
	int			s_len;

	if (*buff)
		ft_bzero(buff, ft_strlen(buff));
	ft_strcpy(buff, ls->dir_num == 1 ? curr_dir : ls->list[i]->sub_dir_list);
	s_len = ft_strlen(buff) + 4;
	ft_strcat(buff, " -> ");
	if ((len = readlink(str, buff + s_len, 1024 - (s_len + 1))) != -1)
		buff[len + s_len] = '\0';
	return (buff);
}

char	*set_perm(t_ls *ls, int i)
{
	INIT;
	S_ISDIR(ls->list[i]->buf.st_mode) ? str[0] = 'd' : 0;
	S_ISBLK(ls->list[i]->buf.st_mode) ? str[0] = 'b' : 0;
	S_ISLNK(ls->list[i]->buf.st_mode) ? str[0] = 'l' : 0;
	S_ISREG(ls->list[i]->buf.st_mode) ? str[0] = '-' : 0;
	S_ISCHR(ls->list[i]->buf.st_mode) ? str[0] = 'c' : 0;
	S_ISFIFO(ls->list[i]->buf.st_mode) ? str[0] = 'p' : 0;
	S_ISSOCK(ls->list[i]->buf.st_mode) ? str[0] = 's' : 0;
	str[1] = (ls->list[i]->buf.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (ls->list[i]->buf.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (ls->list[i]->buf.st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (ls->list[i]->buf.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (ls->list[i]->buf.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (ls->list[i]->buf.st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (ls->list[i]->buf.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (ls->list[i]->buf.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (ls->list[i]->buf.st_mode & S_IXOTH) ? 'x' : '-';
	if (ls->list[i]->buf.st_mode & S_ISUID)
		str[3] = (ls->list[i]->buf.st_mode & S_IXUSR) ? 's' : 'S';
	if (ls->list[i]->buf.st_mode & S_ISGID)
		str[6] = (ls->list[i]->buf.st_mode & S_IXGRP) ? 's' : 'l';
	if (ls->list[i]->buf.st_mode & S_ISVTX)
		str[9] = (ls->list[i]->buf.st_mode & S_IXOTH) ? 't' : 'T';
	return (str);
}
