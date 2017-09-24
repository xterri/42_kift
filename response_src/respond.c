/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   respond.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 21:49:54 by twalton           #+#    #+#             */
/*   Updated: 2017/09/23 15:59:25 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char	*unsure_response(void)
{
	return (ft_strdup("I didn't get that"));
}

static char	*response_pt2(int topic, char *str, int negation)
{
	if (topic == EVENTS)
		return (events_response(str, negation));
	if (topic == WHO)
		return (who_response(str, negation));
	if (topic == WHERE)
		return (where_response(str, negation));
	if (topic == TEXT)
		return (text_response(str, negation));
	return (unsure_response());
}

static char	*response(int topic, char *str, int negation)
{
	if (topic == BYE)
		return (bye_response(str));
	if (topic == ALARM)
		return (alarm_response(str, negation));
	if (topic == LIGHTS)
		return (lights_response(str, negation));
	if (topic == EMAIL)
		return (email_response(str, negation));
	if (topic == WEATHER)
		return (weather_response(str, negation));
	if (topic == TRAFFIC)
		return (traffic_response(str, negation));
	if (topic == MUSIC)
		return (music_response(str, negation));
	if (topic == WEB)
		return (web_response(str, negation));
	if (topic == HISTORY)
		return (history_response(str, negation));
	return (response_pt2(topic, str, negation));
}

char		*respond(char *str)
{
	int		topic;
	int		negation;
	char	*reply;
	char	*temp;

	ft_strwtoi(str);
	temp = strjoin(str, " ");
	str = strjoin(" ", temp);
	free(temp);
	topic = get_topic(str);
	negation = count_negations(str);
	reply = response(topic, str, negation);
	free(str);
	return (reply);
}
