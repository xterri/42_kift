/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alarm_response.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 22:02:16 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 20:05:59 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char	*actual_word(int time_measurement, int plural)
{
	if (time_measurement == HOURS && plural)
		return (strdup(" hours."));
	if (time_measurement == HOURS && !plural)
		return (strdup(" hour."));
	if (time_measurement == MINUTES && plural)
		return (strdup(" minutes."));
	if (time_measurement == MINUTES && !plural)
		return (strdup(" minute."));
	if (time_measurement == SECONDS && plural)
		return (strdup(" seconds."));
	if (time_measurement == SECONDS && !plural)
		return (strdup(" second."));
	return (NULL);
}

static char	*when_alarm_is_set(int time, int time_measurement)
{
	char *phrase1;
	char *phrase2;
	char *phrase3;
	int plural;
	char num[30];

	if (time == 1)
		plural = 0;
	else
		plural = 1;
	phrase1 = strdup("alarm will be set to go off in ");
	snprintf(num, 30, "%d", time);
	phrase2 = strdup(num);
	phrase3 = strjoin(phrase1, phrase2);
	free(phrase2);
	free(phrase1);
	phrase1 = actual_word(time_measurement, plural);
	phrase2 = strjoin(phrase3, phrase1);
	free(phrase3);
	free(phrase1);
	return (phrase2);
}

char	*alarm_response(char *str, int negation)
{
	int time;
	int time_measurement;

	if (negation)
		return (strdup("ok I won't set an alarm."));
	time = get_first_num(str);
	time_measurement = find_time_phrase(str);
	if (!time)
		return (strdup("I don't know when to set the alarm."));
	if (!time_measurement)
	{
		if (time < 5 || time % 5 != 0)
			time_measurement = HOURS;
		else
			time_measurement = MINUTES;
	}
	return (when_alarm_is_set(time, time_measurement));
}
