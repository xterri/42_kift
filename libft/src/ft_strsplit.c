/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:04:22 by bpierce           #+#    #+#             */
/*   Updated: 2017/06/12 16:43:53 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ind_nth_word(const char *s, char c, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			if (count == n)
				return (i);
			while (s[i] != c && s[i])
				i++;
		}
		while (s[i] == c)
			i++;
	}
	return (i);
}

static int	n_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

static int	len_nth_word(const char *s, char c, int n)
{
	int	index;
	int	len;

	index = ind_nth_word(s, c, n);
	len = 0;
	while (s[index] != c && s[index])
	{
		len++;
		index++;
	}
	return (len);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		num_words;
	int		w_len;
	char	**new;

	i = 0;
	j = 1;
	if (s == NULL)
		return (NULL);
	num_words = n_words(s, c);
	new = (char **)malloc(sizeof(*new) * (num_words + 1));
	if (new == NULL)
		return (NULL);
	while (j <= num_words)
	{
		w_len = (size_t)len_nth_word(s, c, j);
		new[i] = ft_strnew(w_len + 1);
		ft_strncpy(new[i], &s[ind_nth_word(s, c, j)], w_len);
		i++;
		j++;
	}
	new[i] = 0;
	return (new);
}
