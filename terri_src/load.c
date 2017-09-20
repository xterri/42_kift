/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 16:32:43 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/13 17:30:01 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		load(const char *file)
{
	t_node			*new_node;
	int				ret;
	char			*line;
	char			*val;
	unsigned int	index;

	ft_memset(g_root, 0, sizeof(t_node));
	int	data = open(file, O_RDONLY);
	if (!data)
	{
		ft_putendl_fd("File could not be opened", 2);
		return (-1);
	}
	while ((ret = get_next_line(data, &line)) != -1)
	{
		if (ret == 0)
			break ;
		new_node = (t_node *)ft_memalloc(sizeof(t_node));
		val = ft_strchr(line, ',');
		new_node->key = ft_strnew(val - line);
		new_node->value = ft_strnew(ft_strlen(val) - 2);
		ft_strncpy(new_node->key, line, val - line);
		ft_strcpy(new_node->value, val + 2);
		index = hash(new_node->key);
		if (!g_root[index])
			g_root[index] = new_node;
		else if (g_root[index])
		{
			new_node->next = g_root[index];
			g_root[index] = new_node;
		}
		else
			return (-1);
		free(line);
	}
	close(data);
	return (0);
}
