/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_response.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynh <thuynh@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 22:20:33 by thuynh            #+#    #+#             */
/*   Updated: 2017/09/24 22:26:28 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*how_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (ft_strdup("I think you ought to know, I'm feeling very \
					depressed. Not like you care, nobody ever cares"));
	return (ft_strdup("I'm very fine, and you?"));
}
