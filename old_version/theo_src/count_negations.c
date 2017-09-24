/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_negations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:22:36 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 21:26:51 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	free_array(char **negations)
{
	int i;

	i = 0;
	while (negations[i])
		free(negations[i++]);
}

static int	word_occurence(char *word, char *str)
{
	int sum;

	sum = -1;
	while (str)
	{
		str = strstr(str, word);
		if (str)
			str += strlen(word) - 1;
		++sum;
	}
	return (sum);
}

static void	fill_in_negations(char **negations)
{
	negations[0] = strdup("n't ");
	negations[1] = strdup(" no ");
	negations[2] = strdup(" not ");
	negations[3] = strdup(" none ");
	negations[4] = strdup(" never ");
	negations[5] = strdup(" off ");
	negations[6] = NULL;
}

int	count_negations(char *str)
{
	char *negations[7];
	int sum;
	int i;

	fill_in_negations(negations);
	sum = 0;
	i = 0;
	while (negations[i])
	{
		sum += word_occurence(negations[i], str);
		++i;
	}
	free_array(negations);
	return (sum);
}
