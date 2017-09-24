/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 14:05:21 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/22 02:44:55 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	server_info(struct sockaddr_in *serv, t_socket *s)
{
	ft_putstr("Server Address: ");
	ft_putstr(inet_ntoa(serv->sin_addr));
	ft_putstr(": ");
	ft_putnbr(s->port);
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	t_socket			s;
	struct sockaddr_in	serv_addr;

	argc < 2 ? error_message("Error missing port.") : 0;
	ft_bzero(&s, sizeof(s));
	s.port = ft_atoi(argv[1]);
	if ((s.server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error_message("Error opening socket.");
	ft_bzero(&serv_addr, sizeof(serv_addr));
	server_address(&serv_addr, &s);
	if (bind(s.server_socket_fd, (struct sockaddr *)&serv_addr,
				sizeof(struct sockaddr)) < 0)
		error_message("Error in connection on the server side.");
	server_info(&serv_addr, &s);
	if (listen(s.server_socket_fd, 5) < 0)
		error_message("Not listening. Talk to the Hand.");
	while (1)
		get_client_connection(&s);
	close(s.server_socket_fd);
	return (0);
}
