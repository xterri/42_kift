/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_recv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:00:56 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/24 17:30:36 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	*client_recv(void *socket)
{
	char		buf[256];
	char		to_display[256];
	char		buf2[256];
	t_socket	*s;

	s = (t_socket *)socket;
	while (1)
	{
		ft_bzero(buf, 256);
		ft_bzero(to_display, 256);
		if ((s->n = recv(s->client_socket_fd, buf, 255, 0)) <= 0)
			error_message("Error reading socket.");
		ft_strcpy(to_display, "BAKA: ");
		ft_strcat(to_display, buf);
		add_string_to_list(s->i, to_display, 0xFF5833);
		snprintf(buf2, sizeof(buf2), "say -v \"kyoko\" \"%s\"", buf);
		system(buf2);
		check_special_commands(buf, s);
		if (ft_strequ(buf, "bye bye now"))
			break ;
	}
	system("killall pocketsphinx_continuous");
	exit(0);
	return (NULL);
}
