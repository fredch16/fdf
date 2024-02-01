/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcharbon <fcharbon@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:34:16 by fcharbon          #+#    #+#             */
/*   Updated: 2024/01/15 20:20:55 by fcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <bsd/string.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "get_next_line.h"

int			ft_isalnum(int c);
int			ft_atoi(const char *nptr);
int			ft_isascii(int c);
int			ft_toupper(int c);
int			ft_isalnum(int c);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_isprint(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_tolower(int c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strs_len(char **str);

void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_free_char2(char **tofree);
void		ft_free_char3(char ***tofree);
const char	*ft_strnstr(const char	*big, const	char *little, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strrchr(const char *s, int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
#endif
