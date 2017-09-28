/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:20:16 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/28 14:12:14 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	*client(void *args)
{
	t_args		*a;
	pid_t		pid;
	t_socket	s;
	t_socket	s2;
	pthread_t	t_id[3];

	a = (t_args *)args;
	a->argc != 3 ? error_message("Syntax: ./client hostname port.") : 0;
	client_standby(a->i, &s, &s2);
	pipe(s.fds) < 0 ? error_message("Piping failed") : 0;
	(pid = fork()) < 0 ? error_message("Forking fail") : 0;
	pid == 0 ? client_child(&s) : 0;
	if (pid > 0)
	{
		get_server_connection(&s, &s2, a->argv[1], ft_atoi(a->argv[2]));
		a->i->socket = &s;
		ft_memcpy(&s2, (void *)&s, sizeof(s));
		pthread_create(&t_id[0], NULL, client_recv, &s);
		pthread_create(&t_id[1], NULL, client_send, &s2);
		pthread_join(t_id[0], NULL);
		pthread_cancel(t_id[1]);
		client_close(&s);
		dup2(s.stdin_save, 0);
	}
	return (0);
}
