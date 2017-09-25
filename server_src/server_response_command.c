/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_response_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:55:01 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/24 21:49:45 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	server_response_command(char *str, t_socket *s)
{
	if (ft_strstr(str, "hey baka"))
	{
		if ((s->n = 
		send(s->client_socket_fd, "Hello, what can I do you for?", 29, 0)) < 0)
			error_message("Error writing to client socket fd.");
		ft_bzero(str, 256);
	}
	else
	{
		server_response(str, s);
		return ;
	}
	while ((s->n = recv(s->client_socket_fd, str, 255, 0)))
	{
		s->n < 0 ? error_message("Error reading socket into buffer.") : 0;
		if (!(ft_strequ(str, "\n")))
		{
			server_response(str, s);
			break ;
		}
	}
}
