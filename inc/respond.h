/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   respond.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 19:18:54 by twalton           #+#    #+#             */
/*   Updated: 2017/09/24 22:28:12 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPOND_H
# define RESPOND_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>

# define SECONDS 1
# define MINUTES 2
# define HOURS 3

# define ALARM 1
# define LIGHTS 2
# define EMAIL 3
# define WEATHER 4
# define TRAFFIC 5
# define MUSIC 6
# define WEB 7
# define HISTORY 8
# define TEXT 9
# define WHO 10
# define WHERE 11
# define BYE 12
# define EVENTS 13
# define GATS 14
# define SWEAR 15
# define ID 16
# define HOW 17
# define JOKE 18

char	*respond(char *str);
int		get_topic(char *str);
int		count_negations(char *str);

char	*alarm_response(char *str, int negation);
int		find_time_phrase(char *str);
int		get_first_num(char *str);
char	*lights_response(char *str, int negation);
char	*email_response(char *str, int negation);
char	*weather_response(char *str, int negation);
char	*weather_at(char *location);
char	*traffic_response(char *str, int negation);
char	*music_response(char *str, int negation);
char	*web_response(char *str, int negation);
char	*history_response(char *str, int negation);
char	*text_response(char *str, int negation);
char	*who_response(char *str, int negation);
char	*where_response(char *str, int negation);
char	*bye_response(char *str, int negation);
char	*events_response(char *str, int negation);
char	*gats_response(char *str, int negation);
char	*swear_response(char *str, int negation);
char	*id_response(char *str, int negation);
char	*how_response(char *str, int negation);
char	*joke_response(char *str, int negation);

char	*strjoin(char *str1, char *str2);
void	free_array(char **arr);

#endif
