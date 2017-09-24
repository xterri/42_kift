/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 16:37:56 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/15 15:29:22 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "database.h"

char	*check(const char *key)
{
	int				len;
	char			*cpy;
	unsigned int	index;
	t_node			*trav;
	
	cpy = (char *)key;
	len = ft_strlen(key);
	cpy[len - 1] = '\0'; 
	if (!cpy)
		return ("Sorry, please try again.");
	index = hash(cpy);
	if (g_root[index])
	{
		trav = g_root[index];
		while (trav)
		{
			if (!strcmp(trav->key, cpy))
				return (trav->value);
			else
				trav = trav->next;
		}
	}
	return (NULL);
}
