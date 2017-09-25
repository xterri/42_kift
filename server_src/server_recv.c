/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_recv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:14:54 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/25 16:07:15 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	*server_recv(void *socket)
{
	char		buf[256];
	t_socket	*s;

	s = (t_socket *)socket;
	while (1)
	{
		ft_bzero(buf, 256);
		if ((s->n = recv(s->client_socket_fd, buf, 255, 0)) < 0)
			error_message("Error reading socket into buffer.");
		else if (s->n == 0)
		{
			ft_putendl("Client Disconnected");
			break ;
		}
		(ft_strequ(buf, "hi\n")) ? send(s->client_socket_fd, "Hello", 5, 0) : 0;
		if (ft_strstr(buf, "hey baka") || ft_strstr(buf, "good bye"))
			server_response_command(buf, s);
		if (ft_strstr(buf, "good bye"))
			break ;
	}
	close(s->fds[1]);
	dup2(s->stdout_save, 1);
	return (NULL);
}
