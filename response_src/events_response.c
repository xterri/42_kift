/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_response.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:31:35 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/23 15:49:06 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*events_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (ft_strdup("ok I won't look for any events for you"));
	return (ft_strdup("here are some events near you"));
}
