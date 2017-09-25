/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_response.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 22:12:04 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/25 14:20:42 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*id_response(char *str, int negation)
{
	char	ret[256];

	(void)str;
	if (negation)
		return (ft_strdup("I am not, not BAKA"));
	ft_strcpy(ret, "My name is BAKA, the 'Brilliant Autonomous \
			Knowledgable A.I.'. Nice to meet you.");
	return (ft_strdup(ret));
}
