/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   web_response.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 22:59:58 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 20:08:35 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char	*get_search(char *str)
{
	char *pstart;
	char *pend;
	int search_size;
	char *search;

	pstart = strstr(str, " search ");
	if (!pstart)
		return (NULL);
	pstart += 7;
	pend = strchr(pstart, '\0');
	search_size = pend - pstart;
	search = malloc(sizeof(char) * (search_size + 1));
	memmove(search, pstart, search_size);
	search[search_size] = '\0';
	return (search);
}

static char	*web_search(char *search)
{
	char *reply;

	reply = strjoin("searching for", search);
	free(search);
	return (reply);
}

char	*web_response(char *str, int negation)
{
	char *search;

	if (negation)
		return(strdup("ok I won't search for anything"));
	search = get_search(str);
	return (web_search(search));
}
