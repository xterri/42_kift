/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_topic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:55:29 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 21:28:18 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	get_topic(char *str)
{
	if (strstr(str, " alarm ") || strstr(str, " timer "))
		return (ALARM);
	if (strstr(str,	" lights "))
		return (LIGHTS);
	if (strstr(str,	" email ") || strstr(str, " message ") || strstr(str, " sms "))
		return (EMAIL);
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
	return (0);
}
