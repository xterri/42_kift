/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_time_phrase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:53:21 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 20:06:27 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	free_array(char **unit_array)
{
	int i;

	i = 0;
	while (unit_array[i])
		free(unit_array[i++]);
}

int	find_time_phrase(char *str)
{
	int i;
	char *unit_array[10];

	unit_array[0] = strdup(" seconds ");
	unit_array[1] = strdup(" second ");
	unit_array[2] = strdup(" sea cone ");
	unit_array[3] = strdup(" minute ");
	unit_array[4] = strdup(" minutes ");
	unit_array[5] = strdup(" mints ");
	unit_array[6] = strdup(" hours ");
	unit_array[7] = strdup(" hour ");
	unit_array[8] = strdup(" our ");
	unit_array[9] = NULL;
	i = 0;
	while (unit_array[i])
	{
		if (strstr(str, unit_array[i]))
		{
			free_array(unit_array);
			return (1 + i / 3);
		}
		++i;
	}
	free_array(unit_array);
	return (0);
}
