/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwtoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 19:40:55 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/17 20:17:33 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_ignore_word(char *s)
{
	char	*ignore_word[4];
	int		i;

	ignore_word[0] = "thousand";
	ignore_word[1] = "million";
	ignore_word[2] = "billion";
	ignore_word[3] = "trillion";
	i = -1;
	while (++i < 4)
		if (ft_strnequ(s, ignore_word[i], ft_strlen(ignore_word[i])))
			return (ft_strlen(ignore_word[i]));
	return (0);
}

static int	is_word_to_parse(char *s, char **wordzies)
{
	int		i;

	if (s)
	{
		i = -1;
		while (++i < 28)
			if (ft_strnequ(s, wordzies[i], ft_strlen(wordzies[i])))
				return (1);
	}
	return (0);
}

static char	**get_wordzies(void)
{
	return (ft_strsplit(
				"ten eleven twelve thirteen fourteen fifteen "
				"sixteen seventeen eighteen nineteen twenty thirty forty fifty "
				"sixty seventy eighty ninety zero one two three four five six "
				"seven eight nine", ' '));
}

void		ft_strwtoi(char *s)
{
	char	**wordzies;
	char	*str_to_parse;
	int		i;
	int		wordlen;
	int		wtoi;

	if (s)
	{
		i = -1;
		wordzies = get_wordzies();
		while (s[++i])
		{
			if (wordlen = is_word_to_parse(&s[i], wordzies))
			{
				str_to_parse = get_string_to_parse(&s[i]);
				wtoi = 
			}
			else if ((wordlen = is_ignore_word(&s[i])))
				ft_strcpy(&s[i], &s[i + wordlen]);
		}
	}
}
