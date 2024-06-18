/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvoznese <kvoznese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 03:16:28 by kvoznese          #+#    #+#             */
/*   Updated: 2024/06/18 17:00:37 by kvoznese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 10

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

# define MALLOC_ERROR "ERROR - Malloc did not work for some reason.\n"

int		ft_atoi(const char *str, int *overflow);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *buf, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strrchr(const char *str, int ch);
int		ft_tolower(int c);
int		ft_toupper(int c);

////////////////PART2/////////////////

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//I CHANGE SRTUCT!/////////////BONUS/////////////////

// t_s		*ft_lstnew(int content);
// void	ft_lstadd_front(t_s **lst, t_s *new);
// t_s		*ft_lstlast(t_s *lst);
// int		ft_lstsize(t_s *lst);
// void	ft_lstadd_back(t_s **lst, t_s *new);
// void	ft_lstdelone(t_s *lst, void (*del)(void *));
// void	ft_lstclear(t_s **lst, void (*del)(void *));
// void	ft_lstiter(t_s *lst, void (*f)(void *));

///////////////NEED/////////////////

int		ft_strcmp(char *s1, char *s2);
int		ft_strrncmp(const char *s1, const char *s2, int n);

//////////////GNL///////////////////

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, const char *s2, int len);

/////////gnltest/////////

// char	*null_calloc(char **str, unsigned int count, unsigned int size);
// char	*join(char *s, char c);
// char	*gnl(int fd);

#endif
