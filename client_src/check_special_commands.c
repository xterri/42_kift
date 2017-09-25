/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_special_commands.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 11:49:37 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/25 14:39:57 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	check_special_commands(char *str, t_socket *s)
{
	char	buf[256];
	char	link[256];
	char	*query;

	ft_bzero(link, 256);
	if (ft_strequ(str, "ok let me show you your history"))
		recv_history(s->client_socket_fd);
	if ((query = ft_strstr(str, "searching")))
	{
		query += 14;
		ft_strcpy(link, "https://www.google.com/search?q=");
		ft_strcat(link, query);
	}
	else if (ft_strequ(str, "here are some events near you"))
		ft_strcpy(link, "https://www.eventbrite.com/d/ca--fremont/events/");
	else if (ft_strequ(str, "opening up gats.i o"))
		ft_strcpy(link, "https://gats.io/");
	if (link[0])
	{
		snprintf(buf, sizeof(buf),
			"open -a \"/Applications/Google Chrome.app/\" '%s'", link);
		system(buf);
	}
}
