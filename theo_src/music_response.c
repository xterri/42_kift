/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_response.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:32:46 by twalton           #+#    #+#             */
/*   Updated: 2017/09/07 22:32:46 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "respond.h"

static char	*get_song(char *str)
{
	char *pstart;
	char *pend;
	char *song;
	int name_length;

	if (!(pstart = strstr(str, " listen to ")) && !(pstart = strstr(str, " play ")))
		return (NULL);
	if (pstart[1] == 'l')
		pstart += 11;
	else
		pstart += 6;
	pend = strchr(pstart, '\0');
	name_length = pend - pstart;
	song = malloc(sizeof(char) * (name_length + 1));
	memmove(song, pstart, name_length);
	song[name_length] = '\0';
	return (song);
}

static char	*play_song(char *song)
{
	char *reply;

	reply = strjoin("ok I will play ", song);
	free(song);
	return (reply);
}

char	*music_response(char *str, int negation)
{
	char *song;

	(void)negation;
	song = get_song(str);
	if (!song)
		return (strdup("what music do you want?"));
	return (play_song(song));
}
