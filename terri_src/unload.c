/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 16:29:46 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/13 16:29:56 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "database.h"

void	unload(void)
{
	int		i;
	t_node	*tmp;
	t_node	*trav;

	i = 0;
	while (i < HASH_SIZE)
	{
		trav = g_root[i];
		while (trav)
		{
			tmp = trav;
			trav = trav->next;
			free(tmp);
		}
		i++;
	}
}
