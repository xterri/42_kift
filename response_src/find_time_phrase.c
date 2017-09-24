/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_time_phrase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 17:53:21 by twalton           #+#    #+#             */
/*   Updated: 2017/09/22 03:47:15 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	find_time_phrase(char *str)
{
	int		i;
	char	*unit_array[10];

	unit_array[0] = ft_strdup(" seconds ");
	unit_array[1] = ft_strdup(" second ");
	unit_array[2] = ft_strdup(" sea cone ");
	unit_array[3] = ft_strdup(" minute ");
	unit_array[4] = ft_strdup(" minutes ");
	unit_array[5] = ft_strdup(" mints ");
	unit_array[6] = ft_strdup(" hours ");
	unit_array[7] = ft_strdup(" hour ");
	unit_array[8] = ft_strdup(" our ");
	unit_array[9] = NULL;
	i = 0;
	while (unit_array[i])
	{
		if (ft_strstr(str, unit_array[i]))
		{
			free_array(unit_array);
			return (1 + i / 3);
		}
		++i;
	}
	free_array(unit_array);
	return (0);
}
