/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 21:04:27 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/16 21:17:50 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** gcc src/ft_wtoi.c -I inc/ libft.a
*/

static long long	get_rest(char **num)
{
	char		*wordzies[4];
	long long	numbers[4];
	int			i;

	wordzies[0] = "thousand";
	wordzies[1] = "million";
	wordzies[2] = "billion";
	wordzies[3] = "trillion";
	numbers[0] = 1000;
	numbers[1] = 1000000;
	numbers[2] = 1000000000;
	numbers[3] = 1000000000000;
	i = -1;
	while (++i < 4)
	{
		if (!(ft_strncmp(*num, wordzies[i], ft_strlen(wordzies[i]))))
		{
			*num += ft_strlen(wordzies[i]);
			return (numbers[i]);
		}
	}
	return (-1);
}

static void			instantiate_stuff(char ***wordzies, int *numbers)
{
	int		i;

	*wordzies = ft_strsplits("ten eleven twelve thirteen fourteen fifteen \
			sixteen seventeen eighteen nineteen twenty thirty forty fifty \
			sixty seventy eighty ninety zero one two three four five six \
			seven eight nine", " \t");
	i = -1;
	while (++i < 29)
	{
		if (i < 11)
			numbers[i] = i + 10;
		else if (i < 18)
			numbers[i] = (i - 8) * 10;
		else if (i < 28)
			numbers[i] = (i - 18);
		else if (i == 28)
			numbers[i] = -1;
	}
}

static long long	get_initial(char **num, int i, int extra)
{
	char		**wordzies;
	int			numbers[29];

	instantiate_stuff(&wordzies, numbers);
	while (++i < 28)
	{
		if (!(ft_strncmp(*num, wordzies[i], ft_strlen(wordzies[i]))))
		{
			*num += ft_strlen(wordzies[i]);
			if (i > 9 && i < 18)
				extra = get_initial(num, -1, 0);
			else if (i > 18 || i < 9)
			{
				if (!(ft_strncmp(*num, "hundred", 7)))
				{
					*num += (!(ft_strncmp(*num, "hundredand", 10))) ? 10 : 7;
					extra = get_initial(num, -1, 0);
					numbers[i] = (numbers[i] * 100);
				}
			}
			break ;
		}
	}
	ft_arraydel(wordzies);
	return (numbers[i] + (extra != -1 ? extra : 0));
}

static void			move_to_next_legitimate_word(char **s)
{
	char	**wordzies;
	int		i;

	wordzies = ft_strsplits("ten eleven twelve thirteen fourteen fifteen \
			sixteen seventeen eighteen nineteen twenty thirty forty fifty \
			sixty seventy eighty ninety zero one two three four five six \
			seven eight nine", " \t");
	while (**s)
	{
		i = -1;
		while (++i < 28)
		{
			if (!(ft_strncmp(*s, wordzies[i], ft_strlen(wordzies[i]))))
			{
				ft_arraydel(wordzies);
				return ;
			}
		}
		*s += 1;
	}
	ft_arraydel(wordzies);
}

long long			ft_wtoi(char *num)
{
	char		*string;
	long long	final;
	long long	*section;
	long long	tmp;
	int			i;

	i = -1;
	section = (long long *)ft_memalloc(sizeof(long long) * 13);
	string = ft_strremove(num, " -");
	while (++i < 13 && *string)
	{
		final = 0;
		if ((tmp = (long long)get_initial(&string, -1, 0)) != -1)
			final += tmp;
		if ((tmp = get_rest(&string)) != -1)
			final *= tmp;
		section[i] = final;
		move_to_next_legitimate_word(&string);
	}
	final = section[0] + section[1] + section[2] + section[3] +
			section[4] + section[5] + section[6] + section[7] +
			section[8] + section[9] + section[10] + section[11] +
			section[12];
	free(section);
	return (final);
}
