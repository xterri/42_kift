/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_response.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:36:06 by twalton           #+#    #+#             */
/*   Updated: 2017/09/15 20:07:21 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*lights_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (strdup("turning lights off"));
	return (strdup("turning lights on"));
}
