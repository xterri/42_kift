/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 19:33:19 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/24 19:33:56 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	client_close(t_socket *s)
{
	close(s->server_socket_fd);
	close(s->client_socket_fd);
}
