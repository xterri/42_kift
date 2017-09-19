/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:14:51 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/18 11:07:20 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	recv_history(int cli_fd)
{
	int		ret;
	int		log_fd;
	char	*buf;

	if (!(log_fd = open("log.txt", O_WRONLY)))// | O_CREAT | O_TRUNC,	S_IRUSR | S_IWUSR)))
	{
		perror("File cannot be opened");
		exit(0);
	}
	if (!(buf = ft_strnew(255)))
	{
		ft_putnull("Failed to malloc.");
		return ;
	}
	ft_bzero(buf, 256);
	while ((ret = recv(cli_fd, buf, 255, 0)) != -1)
	{
		if (ft_strstr(buf, "-----------\n"))
		{
			close(log_fd);
			return ;
		}
		write(log_fd, buf, ft_strlen(buf));
		ft_bzero(buf, 256);
	}
	if (ret < 0)
	{
		perror("Error reading socket");
		close(log_fd);
		exit(0);
	}
	close(log_fd);
}
