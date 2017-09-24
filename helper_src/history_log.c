/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_log.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 17:23:08 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/17 15:20:31 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	history_log(char *str, void *socket)
{
	t_socket	*s;
	char		*tim;
	FILE		*file;
	time_t		t;

	t = time(0);
	s = (t_socket *)socket;
	if (!(file = fopen("log.csv", "a")))
	{
		perror(0);
		exit(0);
	}
	tim = ft_strnew(ft_strlen(ctime(&t)));
	ft_strcpy(tim, ctime(&t));
	tim[ft_strlen(tim) - 1] = '\0';
	fprintf(file, "%s, %s, %s\n", tim, s->client_ip, str);
	free(tim);
	fclose(file);
}
