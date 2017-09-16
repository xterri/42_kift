/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   respond.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 21:49:54 by twalton           #+#    #+#             */
/*   Updated: 2017/09/06 21:49:54 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "respond.h"

static char	*unsure_response(void)
{
	return (strdup("I didn't get that"));
}

static char	*response(int topic, char *str, int negation)
{
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
	return (unsure_response());
}

char	*respond(char *str)
{
	int topic;
	int negation;
	char *reply;
	char *temp;

	temp = strjoin(str, " ");
	str = strjoin(" ", temp);
	free(temp);
	topic = get_topic(str);
	negation = count_negations(str);
	reply = response(topic, str, negation);
	free(str);
	return (reply);
}
