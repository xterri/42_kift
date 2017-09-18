/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:04:22 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/09 21:25:51 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_character(char c, char *chrctrs)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(chrctrs);
	while (chrctrs[i] != c && chrctrs[i])
		i++;
	return (len - i);
}

static int	ind_nth_word(const char *s, char *chrctrs, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!(is_character(s[i], chrctrs)))
		{
			count++;
			if (count == n)
				return (i);
			while (!(is_character(s[i], chrctrs)) && s[i])
				i++;
		}
		while (is_character(s[i], chrctrs))
			i++;
	}
	return (i);
}

static int	n_words(const char *s, char *chrctrs)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!(is_character(s[i], chrctrs)))
		{
			count++;
			while (!(is_character(s[i], chrctrs)) && s[i])
				i++;
		}
		while (is_character(s[i], chrctrs) && s[i])
			i++;
	}
	return (count);
}

static int	len_nth_word(const char *s, char *chrctrs, int n)
{
	int	index;
	int	len;

	index = ind_nth_word(s, chrctrs, n);
	len = 0;
	while (!(is_character(s[index], chrctrs)) && s[index])
	{
		len++;
		index++;
	}
	return (len);
}


char		**ft_strsplits(const char *s, char *chrctrs)
{
	int		i;
	int		j;
	int		num_words;
	int		w_len;
	char	**new;

	if (!s || !chrctrs)
		return (NULL);
	i = 0;
	j = 1;
	num_words = n_words(s, chrctrs);
	if (!(new = (char **)malloc(sizeof(char *) * (num_words + 1))))
		return (NULL);
	while (j <= num_words)
	{
		w_len = (size_t)len_nth_word(s, chrctrs, j);
		new[i] = ft_strnew(w_len);
		ft_strncpy(new[i++], &s[ind_nth_word(s, chrctrs, j++)], w_len);
	}
	new[i] = ft_strnew(0);
	return (new);
}
