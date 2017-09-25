/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_response.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 22:12:04 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/24 22:19:30 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*id_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (ft_strdup("I am not, not BAKA"));
	return (ft_strdup("My name is BAKA, short for 'Brilliant Autonomous \
				Knowledgable A.I. Nice to meet you."));
}
