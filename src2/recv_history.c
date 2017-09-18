/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:14:51 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/18 11:23:24 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	recv_history(int cli_fd)
{
	int		ret;
	int		log_fd;
	char	*buf;

	if (!(log_fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC,
					S_IRUSR | S_IWUSR)))
	{
		perror("File cannot be opened");
		exit(0);
	}
	if (!(buf = ft_strnew(255)))
	{
		ft_putnull("Failed to malloc.");
		return ;
	}
	while ((ret = recv(cli_fd, buf, 255, 0)))
	{
		if (ret < 0)
		{
			perror("Error reading socket");
			exit(0);
		}
		if (ft_strequ(buf, "end"))
			break ;
		write(log_fd, buf, ft_strlen(buf));
	}
	close(log_fd);
}
