/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 16:22:55 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/20 10:07:23 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATABASE_H
# define DATABASE_H

# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include <strings.h>
# include <stdbool.h>
# include <fcntl.h>
# include "libft.h"
# include "server.h"

# define HASH_SIZE 65535
# define LENGTH 45
# define BUFF_SIZE 4096

typedef struct		s_node
{
	char			*key;
	char			*value;
	struct s_node	*next;
}					t_node;

typedef struct		s_line
{
	char		*str;
	char		*tmp;
	int		fd;
	int		size;
	struct s_line	*next;
}			t_line;

/*
** GLOBAL VARIABLE - GIVES ACCESS TO "DATABASE"
*/
t_node	*g_root[HASH_SIZE];

/*
** FUNCTIONS FOR DATABASE
*/
unsigned int	hash(const char *word);
char			*check(const char *key);
int				load(const char *file);
void			unload(void);
void			history_log(char *str, void *socket);
void			send_history(int fd);
int				get_next_line(const int fd, char **line);

#endif
