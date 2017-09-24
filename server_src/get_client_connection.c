/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_client_connection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:37:56 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/22 02:43:41 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	get_client_connection(t_socket *s)
{
	struct sockaddr_in	cli_addr;
	pthread_t			t_id[2];

	s->clilen = sizeof(cli_addr);
	ft_putendl("Waiting for client to connect...");
	if ((s->client_socket_fd = accept(s->server_socket_fd,
					(struct sockaddr *)&cli_addr, &s->clilen)) < 0)
		error_message("Error on accept.");
	s->client_ip = inet_ntoa(cli_addr.sin_addr);
	ft_putstr("Client connected...");
	ft_putendl(s->client_ip);
	pipe(s->fds) < 0 ? error_message("Piping failed.") : 0;
	s->stdin_save = dup(0);
	s->stdout_save = dup(1);
	pthread_create(&t_id[0], NULL, server_recv, s);
	pthread_create(&t_id[1], NULL, server_send, s);
	pthread_join(t_id[0], NULL);
	pthread_cancel(t_id[1]);
	close(s->client_socket_fd);
}
