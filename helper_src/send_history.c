/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 19:43:31 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/20 20:07:42 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	send_history(int cli_fd)
{
	int		log_fd;
	int		ret;
	char	*line;

	if (!(log_fd = open("log.csv", O_RDONLY)))
		error_message("File could not be opened.");
	if (!(line = ft_strnew(255)))
		error_message("Failed to malloc.");
	ft_bzero(line, 256);
	while ((ret = get_next_line(log_fd, &line)))
	{
		if (ret == -1)
			error_message("Failed to get the next line.");
		write(cli_fd, line, ft_strlen(line));
		write(cli_fd, "\n", 1);
		free(line);
		ft_bzero(line, ft_strlen(line));
	}
	ret == 0 ? write(cli_fd, "<end>", 5) : 0;
	close(log_fd);
}
