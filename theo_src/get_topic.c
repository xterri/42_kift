/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_topic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:55:29 by twalton           #+#    #+#             */
/*   Updated: 2017/09/19 15:23:34 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	get_topic_pt2(char *str)
{
	if (strstr(str, " who ") && strstr(str, " connect"))
		return (WHO);
	if (strstr(str, " where ") && strstr(str, " connect"))
		return (WHERE);
	if (strstr(str, " good bye ") && strstr(str, " baka "))
		return (BYE);
	return (0);
}

int	get_topic(char *str)
{
	if (strstr(str, " alarm ") || strstr(str, " timer "))
		return (ALARM);
	if (strstr(str,	" lights "))
		return (LIGHTS);
	if (strstr(str,	" email "))
		return (EMAIL);
	if (strstr(str, " message ") || strstr(str, " sms "))
		return (TEXT);
	if (strstr(str,	" weather ") || strstr(str, " temperature "))
		return (WEATHER);
	if (strstr(str,	" traffic "))
		return (TRAFFIC);
	if (strstr(str,	" music ") || strstr(str, " play ") ||
		strstr(str, " listen to "))
	{
		return (MUSIC);
	}
	if (strstr(str,	" search "))
		return (WEB);
	if (strstr(str,	" history "))
		return (HISTORY);
	return (get_topic_pt2(str));
}
