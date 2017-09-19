/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 19:43:31 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/18 16:42:00 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	send_history(int fd)
{
	int		log_fd;
	int		ret;
	char	*line;

	if (!(log_fd = open("log.csv", O_RDONLY)))
	{
		write(fd, "Log file does not exist.", 24);
		return ;
	}
	if (!(line = ft_strnew(255)))
	{
		ft_putnull("Failed to malloc.");
		return ;
	}
	ft_bzero(line, 256);
	while ((ret = get_next_line(log_fd, &line)))
	{
		if (ret == -1)
		{
			perror("NOPE");
			return ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	if (ret == 0)
		write(fd, "-----------\n", 12);
	close(log_fd);
}
