/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_side.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:20:16 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/18 11:43:13 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ErrorMessage(const char *msg)
{
	perror(msg);
	exit(0);
}

void	*receive_server_message(void *socket)
{
	char		*buf;
	char		buf2[256];
	t_socket	*s;

	s = (t_socket *)socket;
	if (!(buf = ft_strnew(255)))
		return (ft_putnull("Failed to malloc buf for receiving server messages"));
	while (1)
	{
		ft_bzero(buf, 256);
		if ((s->n = recv(s->client_socket_fd, buf, 255, 0)) <= 0)
			ErrorMessage("Error reading socket");
		ft_putstr("BAKA: ");
		ft_putendl(buf);
		snprintf(buf2, sizeof(buf2), "spd-say \"%s\"", buf);
		system(buf2);
		if (ft_strequ(buf, "ok let me show you your history"))
		{
			recv_history(s->client_socket_fd);
			// Open a new terminal window in ubuntu and displays the log
			system("xterm -hold -e cat log.txt &");
		//	system("rm log.txt");
		}
	}
	free(buf);
	return ((void *)buf);
}

void	*send_message_to_server(void *socket)
{
	char		*buf;
	t_socket	*s;

	s = (t_socket *)socket;
	dup2(s->fds[0], 0);
	if (!(buf = ft_strnew(255)))
		return (ft_putnull("Failed to malloc buf for receiving server messages"));
	while (1)
	{
		ft_bzero(buf, 256);
		if ((s->n = read(s->fds[0], buf, 255)) < 0)
			ErrorMessage("Error reading from stdin to buf");
		if (!(ft_strequ(buf, "\n")))
		{
			ft_strtolower(buf);
			ft_putstr("YOU: ");
			ft_putstr(buf);
		}
		if ((s->n = send(s->client_socket_fd, buf, s->n, 0)) < 0)
			ErrorMessage("Error writing in socket");
	}
	free(buf);
	return ((void *)buf);
}

int		main(int argc, char **argv)
{
	pid_t			pid;
	t_socket			s;
	t_socket			s2;
	struct sockaddr_in	serv_addr;
	struct hostent		*server;
	pthread_t			t_id[2];

	if (argc != 3)
		return (fprintf(stderr, "Syntax: %s hostname port\n", argv[0]));
	if (pipe(s.fds) < 0)
		return (fprintf(stderr, "Piping failed\n"));
	s.stdin_save = dup(0);
	s.stdout_save = dup(1);
	if ((pid = fork()) < 0)
		ErrorMessage("Forking fail");
	if (pid == 0)
	{
		dup2(s.fds[1], 1);
		system("pocketsphinx_continuous -inmic yes -lm lm_dict/9214.lm -dict lm_dict/9214.dic -logfn /dev/null");
		close(s.fds[1]);
		dup2(s.stdout_save, 1);
	}
	else
	{
		if ((s.client_socket_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
			ErrorMessage("Error opening socket");
		s.port = ft_atoi(argv[2]);
		if (!(server = gethostbyname(argv[1])))
			return (fprintf(stderr, "Host doesn't exist\n"));
		ft_bzero(&serv_addr, sizeof(serv_addr));
		serv_addr.sin_family = PF_INET;
		serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
		bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
		serv_addr.sin_port = htons(s.port);
		if (connect(s.client_socket_fd,
					(struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
			ErrorMessage("Error in connection man");
		s.n = 256;
		ft_bzero(&s2, sizeof(s2));
		ft_memcpy(&s2, (void *)&s, sizeof(s));
		pthread_create(&t_id[0], NULL, receive_server_message, &s);
		pthread_create(&t_id[1], NULL, send_message_to_server, &s2);
		pthread_join(t_id[0], NULL);
		pthread_join(t_id[1], NULL);
		close(s.server_socket_fd);
		close(s.client_socket_fd);
		dup2(s.stdin_save, 0);
	}
	return (0);
}
