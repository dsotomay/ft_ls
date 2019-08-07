/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 17:53:46 by dysotoma          #+#    #+#             */
/*   Updated: 2018/08/04 17:53:49 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>
# include <sys/errno.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>
# define LEN(x) (int)ft_strlen(x)
# define CMP(x, y) ft_strcmp(x, y)
# define SRC(x, y) ft_strrchr(x, y)
# define CPY(x, y) ft_strcpy(x, y)

/*
** main struct
*/

typedef struct	s_subdir
{
	struct stat	buf;
	char		sub_dir_list[1024];
	char		curr_path[1024];
	char		dev_num[256];
	int			d_num;
}				t_subdir;

typedef struct	s_ls
{
	int			a;
	int			l;
	int			r;
	int			up_r;
	int			one;
	int			t;
	t_subdir	**list;
	struct stat buf;
	int			len_dir_name;
	int			len_size;
	int			len_uid;
	int			len_gid;
	int			len_nlnk;
	int			dir_num;
	int			blk_size;
	int			tmp;
	char		*error;
	char		*curr_dir;
	t_queue		*queue;
}				t_ls;

int				main(int ac, char **av);
void			ls_parse(char *curr_dir, t_ls *ls);
void			ft_qsort(char **arr, int low, int high, t_ls *ls);
void			ft_qsort_struct(int low, int high, t_ls *ls);

/*
** printing
*/

void			print(t_ls *ls, int i);
void			print_long(char *path, t_ls *ls, int i, char *curr_dir);

/*
** length functions
*/

void			ls_reset(t_ls *ls);
int				number_of_dir(char *str, t_ls *ls);
int				get_len(t_ls *ls, struct dirent *dp, int *i);
int				get_len_full(t_ls *ls, struct dirent *dp, int *i);
void			get_len_link(t_ls *ls, struct dirent *dp, int i);

/*
** helper functions
*/

char			*set_perm(t_ls *ls, int i);
void			flag(char *str, t_ls *ls);
int				cmp(char *s1, char *s2, t_ls *ls);
int				list_cmp(char *s1, char *s2, t_ls *ls, int *i);
char			*get_link(char *str, t_ls *ls, int i, char *curr_dir);

/*
** list functions
*/

void			free_list(t_ls *ls);
void			ls_l(char *curr_dir, t_ls *ls);
int				make_list(char *str, t_ls *ls);
void			list_content(char *str, t_ls *ls);

#endif
