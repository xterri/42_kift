/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_topic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:55:29 by twalton           #+#    #+#             */
/*   Updated: 2017/09/24 22:31:22 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	get_topic_pt2(char *str)
{
	if (ft_strstr(str, " events "))
		return (EVENTS);
	if (ft_strstr(str, " history "))
		return (HISTORY);
	if (ft_strstr(str, " gats "))
		return (GATS);
	if (ft_strstr(str, " fuck ") || ft_strstr(str, " shit ") || 
			ft_strstr(" bitch "))
		return (SWEAR);
	if (ft_strstr(str, " joke "))
		return (JOKE);
	if (ft_strstr(str, " what's your name ") || ft_strstr(str, " who are you "))
		return (ID);
	if (ft_strstr(str, " who ") && ft_strstr(str, " connect"))
		return (WHO);
	if (ft_strstr(str, " where ") && ft_strstr(str, " connect"))
		return (WHERE);
	return (0);
}

int			get_topic(char *str)
{
	if (ft_strstr(str, " good bye "))
		return (BYE);
	if (ft_strstr(str, " alarm ") || ft_strstr(str, " timer "))
		return (ALARM);
	if (ft_strstr(str, " lights "))
		return (LIGHTS);
	if (ft_strstr(str, " email "))
		return (EMAIL);
	if (ft_strstr(str, " message ") || ft_strstr(str, " sms "))
		return (TEXT);
	if (ft_strstr(str, " weather ") || ft_strstr(str, " temperature "))
		return (WEATHER);
	if (ft_strstr(str, " traffic "))
		return (TRAFFIC);
	if (ft_strstr(str, " lights "))
		return (LIGHTS);
	if (ft_strstr(str, " music ") || ft_strstr(str, " play ") ||
			ft_strstr(str, " listen to "))
		return (MUSIC);
	if (ft_strstr(str, " search "))
		return (WEB);
	return (get_topic_pt2(str));
}
