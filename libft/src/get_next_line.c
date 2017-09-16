/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 08:46:55 by thuynh            #+#    #+#             */
/*   Updated: 2017/07/20 11:29:06 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		parse_newlines(t_line **lst, char **line)
{
	unsigned int	i;

	i = 0;
	while ((*lst)->str[i] != '\n' && (*lst)->str[i])
		i++;
	if ((*lst)->str[i] == '\n')
	{
		if (!(*line = ft_strsub((*lst)->str, 0, i)))
			return (-1);
		if (!((*lst)->tmp = ft_strdup((*lst)->str + i + 1)))
			return (-1);
		free((*lst)->str);
		(*lst)->str = (*lst)->tmp;
	}
	else if (!(*lst)->str[i])
	{
		if (i == 0)
			return (0);
		if (!(*line = ft_strdup((*lst)->str)))
			return (-1);
		free((*lst)->str);
		(*lst)->str = NULL;
	}
	return (1);
}

t_line	*get_fd(const int fd, t_line **lst)
{
	t_line	*trav;

	trav = *lst;
	while (trav && trav->fd != fd)
		trav = trav->next;
	if (!trav)
	{
		trav = (t_line *)ft_memalloc(sizeof(t_line));
		trav->fd = fd;
		if (!(trav->str = ft_strnew(0)))
			return (NULL);
		trav->next = *lst;
		*lst = trav;
	}
	return (trav);
}

int		make_str(char *str, t_line *lst)
{
	if (!lst->str)
		return (0);
	if (!(lst->tmp = ft_strjoin(lst->str, str)))
		return (0);
	free(lst->str);
	lst->str = NULL;
	if (!(lst->str = ft_strdup(lst->tmp)))
		return (0);
	free(lst->tmp);
	lst->tmp = NULL;
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_line	*root;
	t_line			*tmp;

	if (!line || fd < 0)
		return (-1);
	tmp = get_fd(fd, &root);
	while ((tmp->size = read(tmp->fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[tmp->size] = '\0';
		if (!(make_str(buf, tmp)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (tmp->size < 0)
		return (-1);
	else if (!tmp->size && !tmp->str)
	{
		tmp->fd = 0;
		return (0);
	}
	return (parse_newlines(&tmp, line));
}
