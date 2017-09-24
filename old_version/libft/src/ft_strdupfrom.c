/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupfrom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:41:14 by aderby            #+#    #+#             */
/*   Updated: 2017/06/25 17:06:15 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdupfrom(const char *s, const char c)
{
	unsigned int	i;
	int				len;
	char			*str;

	i = 0;
	if (s && c)
	{
		if (s[i] == '\0')
			return (ft_strnew(1));
		len = ft_strlen(s);
		while (s[i] != c && s[i])
			i++;
		if (!(str = ft_strsub(s, i, (len - i))))
			return (NULL);
	}
	else
		return (NULL);
	return (str);
}
