/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_server_connection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:20:34 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/24 18:01:08 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	get_server_connection(t_socket *s, t_socket *s2, char *host, int port)
{
	struct sockaddr_in	serv_addr;
	struct hostent		*server;

	s->stdin_save = dup(0);
	s->stdout_save = dup(1);
	(s->client_socket_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0 ?
		error_message("Error opening socket.") : 0;
	s->port = port;
	if (!(server = gethostbyname(host)))
		error_message("Host doesn't exist.");
	ft_bzero(&serv_addr, sizeof(serv_addr));
	server_address(&serv_addr, s);
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,
			server->h_length);
	if (connect(s->client_socket_fd, (struct sockaddr *)&serv_addr,
				sizeof(serv_addr)) < 0)
		error_message("Error in connection on the client side.");
	ft_bzero(&s2, sizeof(s2));
	add_string_to_list(s->i, "Yay! You are connected!", 0x14C06A);
}
