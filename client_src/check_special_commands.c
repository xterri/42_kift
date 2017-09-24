/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_special_commands.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 14:55:18 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/23 16:03:12 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	check_special_commands(char *str, t_socket *s)
{
	char	buf[256];
	char	*query;

	if (ft_strequ(str, "ok let me show you your history"))
		recv_history(s->client_socket_fd);
	if ((query = ft_strstr(str, "searching for ")))
	{
		query += 14;
		snprintf(buf, sizeof(buf), "open "
				"-a \"/Applications/Google Chrome.app/\" "
				"'https://www.google.com/search?q=\"%s\"'", query);
		system(buf);
		return ;
	}
	if (ft_strequ(str, "here are some events near you"))
	{
		system("open "
				"-a \"/Applications/Google Chrome.app/\" "
				"'https://www.eventbrite.com/d/ca--fremont/events/'");
	}
}
