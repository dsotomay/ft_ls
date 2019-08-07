/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 09:26:59 by dysotoma          #+#    #+#             */
/*   Updated: 2018/02/23 12:13:52 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"

# define BUFF_SIZE 100

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_queue
{
	struct s_list	*start;
	struct s_list	*end;
}				t_queue;

/*
**	math
*/

int				ft_abs(int a, int b);
int				ft_atoi(const char *str);
char			*ft_itoa(int64_t n);
char			*ft_itoa_base(int64_t n, int base);
char			*ft_utoa_base(uint64_t num, int base);

/*
**	memory
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *str, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_realloc(void *ptr, size_t size);
void			ft_swap_array(char **a, char **b);
void			ft_swap(void **a, void **b);

/*
** numbers
*/

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** write
*/

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** string
*/

char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_ws_to_strncpy(char *dest, const wchar_t *src, size_t n);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *str1, const char *str2);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strncat(char *dest, const char *src, size_t nb);
char			*ft_strrchr(const char *str, int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *str);
size_t			ft_wstrlen(const wchar_t *str);
size_t			ft_strlcat(char *dest, const char *src, size_t dstsize);
char			*ft_strcat(char *dest, const char *src);

/*
** linked list
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** queues
*/

t_queue			*ft_queue();
char			*dequeue(t_queue *q);
void			enqueue(t_queue *q, void *content);

/*
** My functions
*/

int				get_next_line(const int fd, char **line);

#endif
