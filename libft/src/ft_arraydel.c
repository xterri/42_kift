/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 19:08:09 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/19 19:00:40 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arraydel(char **array)
{
	int		i;

	i = -1;
	while (array[++i][0])
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array[i]);
	array[i] = NULL;
	free(array);
}
