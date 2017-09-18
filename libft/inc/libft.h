/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 10:46:43 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/18 11:44:21 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 4096

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_line
{
	char			*str;
	char			*tmp;
	int				fd;
	int				size;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strdupuntil(const char *s, const char c);
char				*ft_strdupfrom(const char *s, const char c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
					size_t len);
char				*ft_strrev(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strccount(char *str, char c);
int					ft_strccountto(char *str, char c);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_iswhitespace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_strtoupper(char **s);
void				ft_strtolower(char *s);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strdeltwo(char **as, char **as2);
void				ft_strdelthree(char **as, char **as2, char **as3);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strfsub(char **s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strfjoin(char **s1, const char *s2);
char				*ft_strffjoin(char **s1, char **s2);
char				*ft_strfremalloc(char **s);
char				*ft_strfresize(char **s, size_t newsize);
char				*ft_strofchars(const char c, size_t num);
char				*ft_strtrim(char const *s);
char				*ft_strctrim(char const *s, const char c);
char				**ft_strsplit(char const *s, char c);
char				**ft_strsplits(char const *s, char *chrctrs);
char				*ft_strfindnreplace(char *s, char f, char r, int n);
char				*ft_itoa(int n);
char				*ft_itoa_base(int value, int base);
void				ft_putchar(char c);
size_t				ft_putchars(const char c, size_t n);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_puterror(const char *error_message, int return_value);
void				*ft_putnull(const char *error_message);
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_swap(int *a, int *b);
char				**ft_arraynew(int width, int height);
char				***ft_arraynew4d(int width, int height, int depth);
int					ft_arraylen(const char **array);
void				ft_arraydel(char **array);
char				*ft_strremove(const char *string, char *remove_chars);
long long			ft_wtoi(char *num);
void				ft_setdoubletozero(double *a, double *b, double *c,
					double *d);
void				ft_setunsignedinttozero(unsigned int *a, unsigned int *b,
					unsigned int *c, unsigned int *d);
void				ft_setunsignedshorttozero(unsigned short *a,
					unsigned short *b, unsigned short *c, unsigned short *d);
void				ft_setnull(void *a, void *b, void *c, void *d);
int					ft_rgb_to_hex(short r, short g, short b);
int					ft_shade_colour(int colour, double percent,
					double constant);
double				ft_percentof(double a, double percent);
int					ft_abs(int n);
int					ft_sign(int n);

#endif
