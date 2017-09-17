/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 16:22:35 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/05 16:29:33 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "database.h"

unsigned int	hash(const char *word)
{
	int		i, sum;

	i = 0;
	sum = 0;
	while (word[i] != '\0')
	{
		sum += word[i];
		i++;
	}
	return (sum % HASH_SIZE);
}
