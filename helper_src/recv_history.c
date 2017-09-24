/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:14:51 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/22 03:25:49 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	recv_history(int cli_fd)
{
	int		ret;
	int		log_fd;
	char	buf[256];

	if (!(log_fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC,
					S_IRUSR | S_IWUSR)))
		error_message("File could not be opened.");
	ft_bzero(buf, 256);
	while ((ret = recv(cli_fd, buf, 255, 0)) != -1)
	{
		if (ft_strstr(buf, "<end>"))
		{
			write(log_fd, buf,
					ft_strlen(buf) - ft_strlen(ft_strstr(buf, "<end>")));
			close(log_fd);
			system("open log.txt");
			return ;
		}
		write(log_fd, buf, ft_strlen(buf));
		ft_bzero(buf, 256);
	}
	if (ret < 0)
		error_message("Error reading socket");
	close(log_fd);
}
