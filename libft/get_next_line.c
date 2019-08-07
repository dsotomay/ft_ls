/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 22:59:42 by dysotoma          #+#    #+#             */
/*   Updated: 2018/07/13 23:33:20 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	split_str_by_newline(char *str, char **before, char **after)
{
	size_t len;
	size_t newline_pos;

	len = ft_strlen(str);
	if (len == 0)
	{
		newline_pos = len;
		*after = str;
	}
	else
	{
		newline_pos = ft_strchr(str, '\n') - str;
		newline_pos == 0 ?
			*after = ft_strsub(str, newline_pos + 1, len) :
			(*after = ft_strsub(str, newline_pos + 1, len - newline_pos - 1));
	}
	*before = ft_strsub(str, 0, newline_pos);
	free(str);
}

static int	set_str(char **str, char **line, char **temp, int *flag)
{
	int i;

	i = 0;
	if (ft_strchr(*str, '\n'))
	{
		*temp = ft_strdup(*str);
		free(*str);
		split_str_by_newline(*temp, line, str);
		*flag = 1;
	}
	else
	{
		if (**str)
			i = 1;
		*line = *str;
		*str = NULL;
	}
	return (i);
}

static int	read_to_buff(char **str, const int fd, char **line, int *flag)
{
	ssize_t		i;
	char		*full_string;
	char		*temp;
	char		read_buffer[BUFF_SIZE + 1];

	i = BUFF_SIZE;
	read_buffer[0] = '\0';
	while (!ft_strchr(read_buffer, '\n') && i == BUFF_SIZE)
	{
		ft_bzero(read_buffer, BUFF_SIZE + 1);
		if ((i = read(fd, read_buffer, BUFF_SIZE)) < 0)
			return (-1);
		if (i == 0)
			break ;
		full_string = ft_strjoin(*str, read_buffer);
		free(*str);
		*str = full_string;
	}
	if (set_str(str, line, &temp, flag))
		i = 1;
	return ((int)i);
}

int			get_next_line(const int fd, char **line)
{
	static char *str[5000];
	int			i;
	int			flag;

	flag = 0;
	if (fd < 0 || read(fd, 0, 0) < 0 || !line)
		return (-1);
	if (!str[fd])
		if (!(str[fd] = ft_memalloc(sizeof(char))))
			return (-1);
	if ((i = read_to_buff(&str[fd], fd, line, &flag)) < 0)
		return (-1);
	if (flag != 0)
		i = str[fd] ? 1 : 0;
	return (i);
}
