/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weather_response.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:00:52 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 21:29:18 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char	*get_weather_loc(char *str)
{
	char *pstart;
	char *pend;
	int word_size;
	char *location;

	pstart = strstr(str, " in ");
	if (!pstart)
		return (NULL);
	pstart += 4;
	pend = strchr(pstart, '\0');
	word_size = pend - pstart;
	location = malloc(sizeof(char) * (word_size + 1));
	memmove(location, pstart, word_size);
	location[word_size] = '\0';
	return (location);
}

char	*weather_response(char *str, int negation)
{
	char *location;

	if (negation)
		return (strdup("ok I won't tell you the weather"));
	location = get_weather_loc(str);
	if (!location)
		return (weather_at(strdup("fremont")));
	return (weather_at(location));
}
