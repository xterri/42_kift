/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 16:22:55 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/17 14:12:02 by thuynh           ###   ########.fr       */
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

typedef struct		s_node
{
	char			*key;
	char			*value;
	struct s_node	*next;
}					t_node;

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

#endif
