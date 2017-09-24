/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_response.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:36:06 by twalton           #+#    #+#             */
/*   Updated: 2017/09/22 03:48:53 by thuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*lights_response(char *str, int negation)
{
	(void)str;
	if (negation)
		return (ft_strdup("turning lights off"));
	return (ft_strdup("turning lights on"));
}
