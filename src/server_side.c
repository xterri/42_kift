/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_side.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 14:05:21 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/19 20:04:06 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ErrorMessage(const char *msg)
{
	perror(msg);
	exit(0);
}

void	*receive_client_message(void *socket)
{
	char		*buf;
	char		*response;
	t_socket	*s;

	s = (t_socket *)socket;
	response = NULL;
	if (!(buf = ft_strnew(255)))
		return (ft_putnull("Failed to malloc buf for receiving client messages"));
	while (1)
	{
		ft_bzero(buf, 256);
		if ((s->n = recv(s->client_socket_fd, buf, 255, 0)) < 0)
			ErrorMessage("Error reading socket into buffer");
		else if (s->n < 0)
		{
			ft_putstr("connection closed\n");
			break ;
		}
		if (ft_strstr(buf, "hey baka"))
		{
			if ((s->n = send(s->client_socket_fd, "Hello", 5, 0)) < 0)
				ErrorMessage("Error writing to client socket fd");
			ft_bzero(buf, 256);
			while ((s->n = recv(s->client_socket_fd, buf, 255, 0)))
			{
				s->n < 0 ? ErrorMessage("Error reading socket into buffer") : 0;
				if (!(ft_strequ(buf, "\n")))
				{
					buf[ft_strlen(buf) - 1] = '\0';
					history_log(buf, s);
					response = respond(buf);
					ft_strequ(response, "%?") ? response = s->client_ip : 0;
					dup2(s->fds[1], 1);
					ft_putendl_fd(buf, s->stdout_save);
					write(s->fds[1], response, ft_strlen(response));
					break ;
				}
			}
		}
		if (ft_strequ(response, "ok let me show you your history"))
			send_history(s->fds[1]);
		if (response && !(ft_strequ(response, s->client_ip)))
		{
			free(response);
			response = NULL;
		}
	}
	close(s->fds[1]);
	dup2(s->stdout_save, 1);
	free(buf);
	return ((void *)buf);
}

void	*send_message_to_client(void *socket)
{
	char		*buf;
	t_socket	*s;

	s = (t_socket *)socket;
	if (!(buf = ft_strnew(255)))
		return (ft_putnull("Failed to malloc buf for receiving client messages"));
	while (1)
	{
		ft_bzero(buf, s->n);
		dup2(s->fds[0], 0);
		if ((s->n = read(s->fds[0], buf, 255)) < 0)
			ErrorMessage("Error reading socket into buffer");
		if ((s->n = send(s->client_socket_fd, buf, s->n, 0)) < 0)
			ErrorMessage("Error writing to client socket fd");
	}
	free(buf);
	close(s->fds[0]);
	dup2(s->stdin_save, 0);
	return ((void *)buf);
}

int		main(int argc, char **argv)
{
	t_socket			s;
	struct sockaddr_in	serv_addr;
	struct sockaddr_in	cli_addr;
	pthread_t			t_id[2];

	if (argc < 2)
		fprintf(stderr, "Error missing port\n");
	else
	{
		bzero(&s, sizeof(s));
		s.port = ft_atoi(argv[1]);
		if ((s.server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
			return (fprintf(stderr, "Error opening socket"));
		bzero(&serv_addr, sizeof(serv_addr));
		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(s.port);
		serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
		if (bind(s.server_socket_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)) < 0)
			ErrorMessage("Error in connection dude");
		ft_putstr("Server Address: ");
		printf("%s:%hd\n", inet_ntoa(serv_addr.sin_addr), s.port);
		if (listen(s.server_socket_fd, 5) < 0)
			ErrorMessage("Not listening. Talk to the Hand.");
		s.n = 256;
		while (1)
		{
			s.clilen = sizeof(cli_addr);
			ft_putstr("Waiting for client to connect...\n");
			if ((s.client_socket_fd = accept(s.server_socket_fd,
							(struct sockaddr *)&cli_addr, &s.clilen)) < 0)
				ErrorMessage("Error on accept");
			s.client_ip = inet_ntoa(cli_addr.sin_addr);
			ft_putstr("Client connected... ");
			ft_putendl(s.client_ip);
			if (pipe(s.fds) < 0)
				ErrorMessage("Piping failed");
			s.stdin_save = dup(0);
			s.stdout_save = dup(1);
			pthread_create(&t_id[0], NULL, receive_client_message, &s);
			pthread_create(&t_id[1], NULL, send_message_to_client, &s);
			pthread_join(t_id[0], NULL);
			close(s.client_socket_fd);
		}
		close(s.server_socket_fd);
	}
	return (0);
}
