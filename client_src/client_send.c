/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_send.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:59:50 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/24 19:30:40 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	*client_send(void *socket)
{
	char		buf[256];
	char		to_display[256];
	t_socket	*s;

	s = (t_socket *)socket;
	dup2(s->fds[0], 0);
	while (1)
	{
		ft_bzero(buf, 256);
		ft_bzero(to_display, 256);
		if ((s->n = read(s->fds[0], buf, 255)) < 0)
			error_message("Error reading from stdin to buf.");
		if (!(ft_strequ(buf, "\n")))
		{
			ft_strtolower(buf);
			ft_strcpy(to_display, "YOU: ");
			ft_strcat(to_display, buf);
			add_string_to_list(s->i, to_display, 0x33D1FF);
		}
		if ((s->n = send(s->client_socket_fd, buf, s->n, 0)) < 0)
			error_message("Error writing in socket.");
	}
	return (NULL);
}
