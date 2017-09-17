/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_log.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 17:23:08 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/17 14:18:55 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	history_log(char *str, void *socket)
{
	t_socket	*s;
	FILE		*file;
	time_t		t;

	t = time(0);
	s = (t_socket *)socket;
	if (!(file = fopen("log.csv", "a")))
	{
		perror(0);
		exit(0);
	}
	!ft_strequ(str, "\n") ? 
		fprintf(file, "%s, %s, %s\n", ctime(&t), s->client_ip, str) : 0;
	fclose(file);
}
