/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:04:57 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:17:26 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# define SIZE_MAX 9223372036854775807

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

size_t			ft_strlcat(char *dst, char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
int				ft_isdigit(int n);
int				ft_isalpha(int j);
int				ft_isalnum(int a);
int				ft_strlen(char *c);
int				ft_tolower(int x);
int				ft_toupper(int j);
int				ft_isascii(int i);
int				ft_isprint(int p);
int				ft_strchr(char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(char *str);
int				ft_memcmp(void *s1, void *s2, size_t n);
int				ft_strcmp(char *s1, char const *s2);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, void *src, size_t len);
void			*ft_calloc(size_t count, size_t size);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			*ft_memmove(void *dst, void *src, size_t len);
void			ft_putendl_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			*ft_memchr(void *s, int c, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
char			*ft_strnstr(char *haystack, char *needle, size_t n);
char			*ft_strrchr(char *s, int c);
char			*ft_itoa(int n);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strdup(char *s1);
char			*ft_strtrim(char *s1, char *set);
char			*ft_strjoin(char *str, char *buff);
char			**ft_split(char *s, char c);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
#endif