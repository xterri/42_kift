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

void	recv_history(void)
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
	while (ret = recv(s->client_socket_fd, buf, 255, 0))
	{
		if (ret < 0)
		{
			perror("Error reading socket");
			exit(0);
		}
		if (ft_strequ(buf, "end"))
		{
			free(buf);
			break ;
		}
		write(log_fd, buf, ft_strlen(buf));
		free(buf);
	}
	close(log_fd);
}
