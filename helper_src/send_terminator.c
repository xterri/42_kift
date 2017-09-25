/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_terminator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:06:20 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/25 16:22:30 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	send_terminator(int cli_fd)
{
	if ((send(cli_fd, "good bye\n", 9, 0)) < 0)
		error_message("Error terminating.");
}
