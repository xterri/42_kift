/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:59:28 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/15 21:32:47 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Turns all upper-case alphabet characters in string to lower case.
*/

void	ft_strtolower(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] > 64 && s[i] < 91)
			s[i] += 32;
		i++;
	}
	return ;
}
