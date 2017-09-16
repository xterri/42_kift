/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weather_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 18:26:44 by twalton           #+#    #+#             */
/*   Updated: 2017/09/08 18:26:44 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "respond.h"

static char	*get_word_begin(char *buf)
{
	char *ret;

	ret = buf;
	while (!isupper(*ret))
		++ret;
	while (!isupper(*++ret))
                ;
	return (ret);
}

static char	*weather_type(char *start)
{
	char *new;
	char *end;
	int size;

	start = get_word_begin(start);
	if (!strncmp("Patchy", start, 5))
		return (strdup("Patchy rainy"));
	if (!(strncmp("Moderate", start, 8)))
		return (strdup("Moderatly rainy"));
	end = strchr(start, '\n');
	size = end - start;
	new = malloc(sizeof(char) * (size + 2));
	memmove(new, start, size);
	if (new[size - 1] != 'y')
		new[size] = 'y';
	else
		new[size] = ' ';
	new[size + 1] = '\0';
	return (new);
}

static char	*temperature(char *start)
{
	char *end;
	int size;
	char *new;

	start = get_word_begin(start);
	start = strchr(start, '\n');
	++start;
	start = strstr(start, "0m ");
	start += 3;
	start = strchr(start, 'm');
	++start;
	if (!isdigit(*start))
	{
		start = strchr(start, 'm');
		++start;
	}
	end = start;
	while (isdigit(*end))
		++end;
	size = end - start;
	new = malloc(sizeof(char) * (size + 1));
	memmove(new, start, size);
	new[size] = '\0';
	return (new);
}

static char	*create_weather_phrase(char *type, char *temp)
{
	char *new;

	new = malloc(sizeof(char) * 100);
	sprintf(new, "The weather is %s with a temperature of %s degrees", type, temp);
	return (new);
}

char	*weather_at(char *location)
{
	char buf[500];
	FILE *fp;
	char *temp[3];

	write(1, "2", 1);
	sprintf(buf, "curl wttr.in/~%s", location);
	if (!(fp = popen(buf, "r")))
		exit(1);
	fread(buf, 499, 1, fp);
	buf[499] = '\0';
	if ((pclose(fp) == -1))
		exit(1);
	temp[0] = weather_type(buf);
	temp[1] = temperature(buf);
	temp[2] = create_weather_phrase(temp[0], temp[1]);
	free(temp[0]);
	free(temp[1]);
	free(location);
	return (temp[2]);
}
