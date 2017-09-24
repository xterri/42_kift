/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 14:05:52 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/24 16:29:48 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

/*
** For server and client side
*/
# include "libft.h"
# include "respond.h"
# include "interface.h"
# include <stdio.h>
# include <fcntl.h>
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

/*
** Struct for get_next_line
*/
# define BUFF_SIZE 4096

typedef struct			s_line
{
	char				*str;
	char				*tmp;
	int					fd;
	int					size;
	struct s_line		*next;
}						t_line;

/*
** Struct for command line arguments
*/

typedef struct			s_args
{
	int					argc;
	char				**argv;
	t_interface			*i;
}						t_args;

/*
** Server functions
*/
void					*server_send(void *socket);
void					*server_recv(void *socket);
void					server_response(char *str, t_socket *s);
void					server_response_command(char *str, t_socket *s);
void					get_client_connection(t_socket *s);

/*
** Client functions
*/
void					*client(void *args);
void					*client_send(void *socket);
void					*client_recv(void *socket);
void					client_child(t_socket *s);
void					check_special_commands(char *str, t_socket *s);
void					get_server_connection(t_socket *s, t_socket *s2,
						char *host, int port);

/*
** Functions for logging client history
*/
void					history_log(char *str, void *socket);
void					send_history(int cli_fd);
void					recv_history(int cli_fd);

/*
** Helper functions
*/
int						get_next_line(const int fd, char **line);
void					error_message(const char *msg);
void					server_address(struct sockaddr_in *serv, t_socket *s);

#endif
