/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_response.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:32:46 by twalton           #+#    #+#             */
/*   Updated: 2017/09/22 03:49:17 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char	*get_song(char *str)
{
	char	*pstart;
	char	*pend;
	char	*song;
	int		name_length;

	if (!(pstart = ft_strstr(str, " listen to ")) &&
			!(pstart = ft_strstr(str, " play ")))
		return (NULL);
	if (pstart[1] == 'l')
		pstart += 11;
	else
		pstart += 6;
	pend = ft_strchr(pstart, '\0');
	name_length = pend - pstart;
	song = (char *)malloc(sizeof(char) * (name_length + 1));
	ft_memmove(song, pstart, name_length);
	song[name_length] = '\0';
	return (song);
}

static char	*play_song(char *song)
{
	char	*reply;

	reply = strjoin("ok I will play ", song);
	free(song);
	return (reply);
}

char		*music_response(char *str, int negation)
{
	char *song;

	(void)negation;
	song = get_song(str);
	if (!song)
		return (ft_strdup("what music do you want?"));
	return (play_song(song));
}
