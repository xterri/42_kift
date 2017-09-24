/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:06:25 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/20 18:52:10 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	server_address(struct sockaddr_in *serv, t_socket *s)
{
	serv->sin_family = AF_INET;
	serv->sin_port = htons(s->port);
	serv->sin_addr.s_addr = htonl(INADDR_ANY);
	s->n = 256;
}
