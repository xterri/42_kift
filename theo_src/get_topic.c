/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_topic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:55:29 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 19:54:11 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "respond.h"

int	get_topic(char *str)
{
	if (strstr(str, " ALARM ") || strstr(str, " TIMER "))
		return (ALARM);
	if (strstr(str,	" LIGHTS"))
		return (LIGHTS);
	if (strstr(str,	"MAIL ") || strstr(str, " MESSAGE ") || strstr(str, " SMS "))
		return (EMAIL);
	if (strstr(str,	" WEATHER ") || strstr(str, " TEMPERATURE "))
		return (WEATHER);
	if (strstr(str,	" TRAFFIC "))
		return (TRAFFIC);
	if (strstr(str,	" MUSIC ") || strstr(str, " PLAY ") ||
		strstr(str, " LISTEN TO "))
	{
		return (MUSIC);
	}
	if (strstr(str,	" SEARCH "))
		return (WEB);
	if (strstr(str,	" HISTORY "))
		return (HISTORY);
	return (0);
}
