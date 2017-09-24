/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_send.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:28:36 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/20 16:53:25 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	*server_send(void *socket)
{
	char		buf[256];
	t_socket	*s;

	s = (t_socket *)socket;
	while (1)
	{
		ft_bzero(buf, s->n);
		dup2(s->fds[0], 0);
		if ((s->n = read(s->fds[0], buf, 255)) < 0)
			error_message("Error reading socket into buffer.");
		if ((s->n = send(s->client_socket_fd, buf, s->n, 0)) < 0)
			error_message("Error writing to client socket fd.");
	}
	close(s->fds[0]);
	dup2(s->stdin_save, 0);
	return ((void *)1);
}
