/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 14:05:52 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/18 11:12:24 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

/*
** For server and client side
*/

# include "libft.h"
# include "database.h"
# include "respond.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <pthread.h>

/*
** For client side only, need 'hostent' struct which stores host info
*/

# include <netdb.h>

typedef struct			s_socket
{
	int					server_socket_fd;
	int					client_socket_fd;
	int					stdin_save;
	int					stdout_save;
	int					fds[2];
	int					tmp_fd;
	int					n;
	char				*client_ip;
	unsigned short		port;
	unsigned int		clilen;
}						t_socket;

void	recv_history(void);
#endif
