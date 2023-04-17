/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avast <avast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:54:35 by avast             #+#    #+#             */
/*   Updated: 2023/03/27 15:36:27 by avast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <syslog.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <limits.h>
# include <sys/stat.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void		call_utils(char c, int *a, va_list ap);
void		call_utils_err(char c, int *a, va_list ap);
char		*extract_line(char *buff);
char		*fill_buffer(int fd, char *buff);
void		free_buff(char **buff);
int			ft_atoi(const char *nptr);
long int	ft_atol(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		ft_free_str(char *s);
void		ft_free_strtab(char **tab, int index);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
int			ft_printf(const char *format, ...);
int			ft_printf_err(const char *format, ...);
int			ft_printf_fd(int fd, const char *format, ...);
void		ft_putad_pf(unsigned long long int p, int *a);
void		ft_putad_err_pf(unsigned long long int p, int *a);
int			ft_putchar_fd(char c, int fd);
void		ft_putchar_pf(char c, int *a);
void		ft_putchar_err_pf(char c, int *a);
void		ft_putendl_fd(char *s, int fd);
void		ft_puthexa(unsigned long long int nbr, char *base, int *a);
void		ft_puthexa_err(unsigned long long int nbr, char *base, int *a);
void		ft_putnbr_fd(int nbr, int fd);
void		ft_putnbr_pf(long int nbr, int *a);
void		ft_putnbr_err_pf(long int nbr, int *a);
int			ft_putstr_fd(char *s, int fd);
void		ft_putstr_pf(char *s, int *a);
void		ft_putstr_err_pf(char *s, int *a);
void		ft_putstrtab(char **tab);
char		**ft_split(char *s, char c);
char		**ft_split_in_two(char *s, char c);
char		*ft_strcapitalize(char *str);
char		*ft_strchr(const char *s, int c);
int			ft_strchr_gnl(char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_strjoin_three(char const *s1, char const *s2, char const *s3);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strreplace(char *str, int start, int len, char *replace);
char		*ft_strrchr(const char *s, int c);
int			ft_strstr(const char *to_find, const char *big);
int			ft_strtab_size(char **tab);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_substr_gnl(char *s, unsigned int start, unsigned int len);
char		**ft_tabdup(char **tab);
void		ft_free_tab(char **tab);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*get_next_line(int fd);
char		*update_buffer(char *buff);

#endif