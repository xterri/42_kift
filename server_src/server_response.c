/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_response.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:18:23 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/22 12:13:35 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	server_response(char *str, t_socket *s)
{
	char		*response;

	str[ft_strlen(str) - 1] = '\0';
	history_log(str, s);
	response = respond(str);
	dup2(s->fds[1], 1);
	ft_putendl_fd(str, s->stdout_save);
	write(s->fds[1], response, ft_strlen(response));
	if (ft_strequ(response, "you are connected at the ip address of "))
		write(s->fds[1], s->client_ip, ft_strlen(s->client_ip));
	if (ft_strequ(response, "ok let me show you your history"))
		send_history(s->fds[1]);
	ft_strdel(&response);
}
