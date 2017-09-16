/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 19:47:07 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 20:07:57 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*strjoin(char *str1, char *str2)
{
	char *new;
	int size;
	int i;

	i = -1;
	size = strlen(str1) + strlen(str2);
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	while (str1[++i])
		new[i] = str1[i];
	new[i] = '\0';
	strcat(new, str2);
	return (new);
}
