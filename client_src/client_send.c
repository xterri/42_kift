/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_send.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:59:50 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/22 02:21:12 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	*client_send(void *socket)
{
	char		*buf;
	t_socket	*s;

	s = (t_socket *)socket;
	dup2(s->fds[0], 0);
	if (!(buf = ft_strnew(255)))
		error_message("Failed to malloc buf for receiving server messages.");
	while (1)
	{
		ft_bzero(buf, 256);
		if ((s->n = read(s->fds[0], buf, 255)) < 0)
			error_message("Error reading from stdin to buf.");
		if (!(ft_strequ(buf, "\n")))
		{
			ft_strtolower(buf);
			ft_putstr("YOU: ");
			ft_putstr(buf);
		}
		if ((s->n = send(s->client_socket_fd, buf, s->n, 0)) < 0)
			error_message("Error writing in socket.");
	}
	free(buf);
	return ((void *)buf);
}
