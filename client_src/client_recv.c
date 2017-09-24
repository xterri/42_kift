/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_recv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:00:56 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/24 13:54:43 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	*client_recv(void *socket)
{
	char		*buf;
	char		buf2[256];
	t_socket	*s;

	s = (t_socket *)socket;
	if (!(buf = ft_strnew(255)))
		error_message("Failed to malloc buf for receiving server messages.");
	while (1)
	{
		ft_bzero(buf, 256);
		if ((s->n = recv(s->client_socket_fd, buf, 255, 0)) <= 0)
			error_message("Error reading socket.");
		ft_putstr("BAKA: ");
		ft_putendl(buf);
		snprintf(buf2, sizeof(buf2), "say -v \"kyoko\" \"%s\"", buf);
		system(buf2);
		check_special_commands(buf, s);
		if (ft_strequ(buf, "bye bye now"))
			break ;
	}
	system("killall pocketsphinx_continuous");
	ft_strdel(&buf);
	return ((void *)buf);
}
